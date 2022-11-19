#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
pthread_t thread_id;
 
void test(int j)
{
  char temp[1024*1024*10] = {0};
  for (int i = 0; i < 10; i++) {
    temp[0] = i;
    temp[0] ++;
    printf("%s %d num = %d!\r\n", __FUNCTION__, __LINE__, temp[0]);
    // test(temp[0]);
  }
}
void *thrd_func(void *arg)
{
    printf("%s %d!\r\n", __FUNCTION__, __LINE__);
    printf("New process:  PID: %d,TID: %u.\r\n",getpid(),pthread_self());
    printf("New process:  PID: %d,TID: %u.\r\n",getpid(),thread_id);
    test(0);
    pthread_exit(NULL); //退出线程
}
int main(void)
{
    if (pthread_create(&thread_id,NULL,thrd_func,NULL)!=0) 
    {
        printf("Create thread error!\r\n");
        exit(1);
    }
    usleep(10000);           //此处一定要加延时，否则子线程还没跑完主线程就结束了。
    return 0;
}
