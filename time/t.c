#include <sys/time.h>
/* #include <mach/clock.h> */
/* #include <mach/mach.h> */
/* #include <mach/mach_time.h> */
#include <chrono>
#include <iostream>

#ifndef NSEC_PER_SEC
#define NSEC_PER_SEC 1000000000ULL
#endif

int main() {
  uint64_t t = mach_absolute_time();
  static mach_timebase_info_data_t timebase_info;
  if (timebase_info.denom == 0) {
    (void)mach_timebase_info(&timebase_info);
  }
  auto nanos = t * timebase_info.numer / timebase_info.denom;
  auto tv_sec = nanos / NSEC_PER_SEC;
  auto tv_nsec = nanos - (tv_sec * NSEC_PER_SEC);
  std::cout << tv_sec << " " << tv_nsec << std::endl;
  return 0;
}

