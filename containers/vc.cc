#include <vector>
// #include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <deque>

int main () {
  std::vector<std::map<int, std::deque<int>>> snaps;
  snaps.resize(4);
  // snaps[3].emplace(std::make_pair(1,1));
  if (snaps[3][1].empty()) {
    std::cout << " empty " << std::endl;
  }
  // std::set<int, std::greater<int>> snaps;
  // // std::vector<int> names = {a , 4};
  // // for (auto u : names) {
  // //   std::cout << u << std::endl;
  // //}
  // auto it = std::find(a.begin(), a.end(), 2);
  // // auto it = std::lower_bound(a.end(), a.begin(), 2);
  // if (it == a.end()) {
  //   std::cout << " end " << std::endl;
  // } else {
  //   std::cout << " not end " << std::endl;
  // }
  // it = true ? ++it : a.end();
  // snaps.insert(a.begin(), it);


  // for (auto u : snaps) {
  //   std::cout << u << std::endl;
  // }
}
