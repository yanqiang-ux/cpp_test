#include <time.h>
#include <iostream>
#include "common/Clock.cc"
#include "common/Cycles.h"

int main() {
  int a  =1;
  utime_mono_t start_stamp = ceph_mono_clock_now();
  for (uint64_t i =0; i < 50000000; i++) {
    ceph_mono_clock_now();
  }
  utime_mono_t end_stamp = ceph_mono_clock_now();
  std::cout << " ceph_mono_clock time " << (end_stamp - start_stamp) << std::endl;
  start_stamp = ceph_mono_clock_now();
  for (uint64_t i =0; i < 50000000; i++) {
    ceph_clock_now();
  }
  end_stamp = ceph_mono_clock_now();
  std::cout << " ceph_clock_now time " << (end_stamp - start_stamp) << std::endl;

//  Cycles::init();
  start_stamp = ceph_mono_clock_now();
  for (uint64_t i =0; i < 50000000; i++) {
    //uint64_t start = Cycles::rdtsc();
    //Cycles::to_microseconds(start);
    Cycles::to_microseconds(Cycles::rdtsc());
  }
  end_stamp = ceph_mono_clock_now();
  std::cout << " cycles time " << (end_stamp - start_stamp) << std::endl;
  start_stamp = ceph_mono_clock_now();
  uint64_t i = 0;
  for (uint64_t i =0; i < 50000000; i++) {
    //uint64_t start = Cycles::rdtsc();
    //Cycles::to_microseconds(start);
    i++/1000;
  }
  end_stamp = ceph_mono_clock_now();
  std::cout << " cycles time " << (end_stamp - start_stamp) << std::endl;
  return 0;
}
