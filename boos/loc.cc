#include <iostream>
// #include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
// #include <boost/thread/thread.hpp>

boost::shared_mutex snaplock;
int count = 0;

// void Counter() {
//   boost::unique_lock<boost::mutex> lock(mutex);
  
//   int i = ++count;
//   std::cout << "count == " << i << std::endl;
// }

int main() {
  // boost::thread_group threads;
  // for (int i = 0; i < 40; ++i) {
  //   threads.create_thread(&Counter);
  // }

  // threads.join_all();
  // boost::unique_lock<boost::mutex> lock(snaplock);
  boost::unique_lock<boost::shared_mutex> wr(snaplock);
  retry:
  snaplock.lock();
  std::cout << " test " << std::endl;
  return 0;
}
