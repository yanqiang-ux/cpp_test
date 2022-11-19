#include "common/Mutex.h"
#include "common/Cond.h"
#include <iostream>


int main () {
  // Mutex lock("Messenger::DispatchQueue::lock");
  // Cond cond;

  // cond.Wait(lock);
  pthread_mutex_t _m;
  pthread_cond_t _c;
  // pthread_mutex_lock(&_m);
  int r = pthread_cond_wait(&_c, &_m);
  // int flag;
  // std::cin >> flag;
}
