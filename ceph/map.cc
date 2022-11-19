#include <map>
#include <iostream>

int main() {
  std::map<int, int> test;
  auto res = test.emplace(1, 1);
  auto r = test.erase(1);
  auto r1 = test.erase(1);
  std::cout << r << " " << r1 << std::endl;
}
