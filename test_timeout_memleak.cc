//#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <pthread.h>
#include "rados/librados.h"
#include "rbd/librbd.h"
#include <iostream>
#include <gperftools/heap-profiler.h>
#include <gperftools/malloc_extension.h>

char *g_test_buffer = NULL;
const uint32_t g_buffer_len = 4194304;

#define TEST_RBD
#define HEAP_PROFILER_STATS_SIZE 2048

static void ceph_heap_profiler_stop()
{
    HeapProfilerStop();
}

static void ceph_heap_profiler_dump(const char *reason)
{
    HeapProfilerDump(reason);
}

static void ceph_heap_profiler_stats(char *buf, int length)
{
    MallocExtension::instance()->GetStats(buf, length);
}

static void ceph_heap_release_free_memory()
{
    MallocExtension::instance()->ReleaseFreeMemory();
}

void *test_entry(void *arg) {
  pthread_t tid = pthread_self();
  uint64_t loop_count = 0;
  int *prt_num = (int *)malloc(sizeof(int));
  *prt_num = -1;
  int rt_num = 0;
  

  while (1) {
    rados_t cluster;
    rados_ioctx_t io; 
    char cluster_name[] = "ceph";
    char user_name[] = "client.admin";
    uint64_t flags = 0;
    char *poolname =  (char *)arg;
    pthread_t ptid = pthread_self();
    char stid[218] = {0};
    snprintf(stid, 217, "test_timeout.%x", ptid);


    if (++loop_count % 1000 == 0) {
      printf("tid = %lu loop %lu\n", tid, loop_count);
    }
    if (loop_count > 10000) {
      rados_ioctx_destroy(io);
      rados_shutdown(cluster);
      printf("%lu: Finish all test\n", tid);
      *prt_num = 0;
      return (void *)prt_num; 
    }

    
    rt_num = rados_create2(&cluster, cluster_name, user_name, flags);
    if(rt_num<0){
      printf("%lu: Couldn't create the cluster handle! %s\n", tid, strerror(-rt_num));
      return (void *)prt_num; 
    }else{
      //printf("\nCreated a cluster handle success. \n");
    } 

    rt_num = rados_conf_read_file(cluster, "/etc/ceph/ceph.conf");
    if(rt_num<0){
      printf("%lu:can't read config file: %s\n", tid, strerror(-rt_num));
      rados_shutdown(cluster);
      return (void *)prt_num; 
    }else{
      //printf("\nRead the config file. \n");
    }

    rt_num = rados_conf_set(cluster, "rados_osd_op_timeout", "5");
    rt_num = rados_conf_set(cluster, "rados_mon_op_timeout", "3");
    rt_num = rados_conf_set(cluster, "debug_objecter", "15");
    rt_num = rados_conf_set(cluster, "debug_ms", "30");
    rt_num = rados_conf_set(cluster, "debug_monc", "10");
    rt_num = rados_conf_set(cluster, "name", stid);

    rt_num = rados_connect(cluster);
    if(rt_num<0){
      printf("%lu:cannot connect to cluster:%s\n", tid, strerror(-rt_num));
      rados_shutdown(cluster);
      return (void *)prt_num; 
    }else{
      //printf("\nConnected to the cluster.\n");
    }

    rt_num = rados_ioctx_create(cluster, poolname, &io);
    if(rt_num<0){
      printf("%lu:cannot open rados pool %s:%s", tid, poolname, strerror(-rt_num));
      rados_shutdown(cluster);
      return (void *)prt_num; 
    }else{
      printf("\nCreated I/O context. \n");
    }

    
    char oid[512] = {'\0'};
    snprintf(oid, 511, "test_timeout.%x", ptid);
    printf("start %s aio.\n", oid);
    int count = 0;
    while (1) {
      int r = 0;
      //count++;
      //if (count > 100) {
      //  if (count == 102)
      //    printf("start sleep .\n");
      //  sleep(1); 
      //  continue; 
      //}
      //printf("count %d .\n", count);
      rados_completion_t my_completion;
      rados_write_op_t op = rados_create_write_op();
      rados_aio_create_completion(NULL, NULL, NULL, &my_completion);

      rados_write_op_write(op, (const char *)g_test_buffer, g_buffer_len, 0);

      r = rados_aio_write_op_operate(op, io, my_completion, oid, NULL, 0);

      rados_aio_wait_for_complete(my_completion);
      r = rados_aio_get_return_value(my_completion);
      if (r < 0 && r != -110 && r != -2) {
        printf("%s aio error:%d\n", oid, r);
        return ((void *)0);;
      } else if(r == -110)  {
        ;//printf("%s aio error:%d\n", oid, r);
      }
      rados_release_write_op(op);
      rados_aio_release(my_completion);
    }

    //printf("\nClosing the connection\n");
    rados_ioctx_destroy(io);
    //printf("\nShut down the handle\n");
    rados_shutdown(cluster);
  }
  return ((void *)0);;
}

int main(int argc, char** argv) {

  char poolname[256] = {'\0'};
  int parallel = 20;
  snprintf(poolname, 256 - 1, "rbd");
  if (argc > 1) {
    strncpy(poolname, argv[1], 256 - 2);
  }
  if (argc > 2) {
    parallel = atoi(argv[2]);
    if (parallel > 100) {
      parallel = 100;
    }
  }

  g_test_buffer = new char[g_buffer_len]; 
  memset(g_test_buffer, 'b', g_buffer_len);

  pthread_t threads[100];

  int i = 0;
  for (i = 0; i < parallel; i++) {
    int r = 0;
    r = pthread_create(&threads[i], NULL, test_entry, (void *) poolname);
    if (r) {
      return -1;
    }
  }
  std::cout << "====================================================================" << std::endl;
  std::cout << " total threads:" << parallel << " poolname:" << poolname << std::endl;
  std::cout << "====================================================================" << std::endl;
  //while (--i >= 0) {
  //  void *retval = 0;
  //  pthread_join(threads[i], &retval);
  //}
  char cmd;
  const char * name = "tc stats:";
  char heap_stats[HEAP_PROFILER_STATS_SIZE];
  while (true) {
    //printf("input char :");
    //c = getc(stdin);
    //printf("the char is :\n");
    //putc(c, stdout);
    std::cout << "pls input cmd:" ;
    std::cin >> cmd;
    std::cout << " inout :" << cmd << std::endl;
    switch (cmd) {
      case 'd':
        {
          std::cout << "ceph_heap_profiler_dump" << std::endl;
          ceph_heap_profiler_dump(name);
          break;
        }
      case 's':
        {
          std::cout << "ceph_heap_profiler_stats" << std::endl;
          ceph_heap_profiler_stats(heap_stats, sizeof(heap_stats));
          std::cout << "heap_stats:" << heap_stats << std::endl;
          break;         
        }
      case 'p':
        {
          std::cout << "ceph_heap_profiler_stop" <<std::endl;
          ceph_heap_profiler_stop();
          break;   
        }
      default:
        std::cout << "invalied char" << std::endl;
    }
  }
  return 0;
} 
