#include <thread>
#include <boost/lockfree/queue.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <random>

boost::lockfree::queue<int, boost::lockfree::fixed_sized<true> > m_queue(1024);
std::vector<std::vector<int>> reads;
int outter = 10;

void writer(int a) {
  for (int j = (0 + a*1024); j < (a+1)*1024; j++) {
    while (true) {
      if (!m_queue.push(j)) {
        // std::cout << " i " << i << " j " << j << " push failed " << std::endl;
        usleep(random() % 5);
      } else {
        break;
      }
    }
  }
}

void reader(int a) {
  for (int i = 0; i < outter; i++) {
    for (int j = 0; j < 1024; j++) {
      while (true) {
        int u = 0;
        if (!m_queue.pop(u)) {
          std::cout << " i " << i << " j " << j << " pop failed " << std::endl;
          usleep(1);
        } else {
          reads[(u/1024)][(u%1024)] = (u % 1024);
          break;
        }
      }
    }
    std::cout << " read " << i << " done " << std::endl;
  }
}

int main () {
  for (int y = 0; y < outter; y++) {
    std::vector<int> tmp;
    tmp.resize(1024);
    reads.push_back(tmp);
  }
  int a = 2;
  std::thread t1(writer, 0);
  std::thread t2(writer, 1);
  std::thread t3(writer, 2);
  std::thread t4(writer, 3);
  std::thread t5(writer, 4);
  std::thread t6(writer, 5);
  std::thread t7(writer, 6);
  std::thread t8(writer, 7);
  std::thread t9(writer, 8);
  std::thread t0(writer, 9);
  std::thread t11(reader, a);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  t7.join();
  t8.join();
  t9.join();
  t0.join();
  t11.join();
  for (int y = 0; y < outter; y++) {
    for (int i = 0; i < 1024; i++) {
      assert(reads[y][i] == i);
      // std::cout << " reads " << reads[y][i] << std::endl;
    }
  }

  // for (int u = 0; u < 1024; u++) {
  //   int tmp;
  //   m_queue.pop(tmp);
  //   std::cout << " tmp " << tmp << std::endl;
  // }

  // getchar();
}


