#include <chrono>
#include <iostream>
#include "common/ceph_timer.h"

int main() {
  uint32_t now = ceph::coarse_real_clock::to_time_t(ceph::coarse_real_clock::now());
  std::cout << " now " << now << std::endl;
}
