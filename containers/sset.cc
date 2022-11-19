#include <iostream>
#include <set>

int main() {
  std::set<int> nn = {1, 2, 3};
  std::set<int> n2 = {1, 2, 3, 4};
  nn.insert(n2.begin(), n2.end());
  for (auto i : nn)  {
    std::cout << i << "," << std::endl;
  }
  std::cout << " n2 size" << n2.size() <<std::endl;
}
