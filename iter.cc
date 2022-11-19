#include <iostream>
#include <map>


int main() {
  std::map<int, int> mm;

  mm.emplace(1,1);
  std::map<int, int>::iterator it, it2;
  it = it2;
  std::cout << " test " << (it == it2) << std::endl;
}
