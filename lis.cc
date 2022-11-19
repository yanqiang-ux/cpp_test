#include <list>
#include <iostream>


int main() {
  std::list <std::list<int>> test;


  for (int i = 0; i < 10; i++) {
    test.emplace_back(1, i);
  }
  std::cout << " size " << test.size() << std::endl;
  for (auto it = test.begin(); it != test.end(); it++) {
    for (auto i = it->begin(); i != it->end(); i++) {
      std::cout << *i << std::endl;
    }
  }
  // for (std::list <int>::iterator j = test.begin(); j != test.end();) {
  //   std::cout << &*j << " v " << *j << std::endl;
  //   if ((*j) % 3 == 0) {
  //     j = test.erase(j);
  //     continue;
  //   }
  //   ++j;
  // }

  // for (std::list <int>::iterator j = test.begin(); j != test.end(); ++j) {
  //   std::cout << &*j << " v " << *j << std::endl;
  // }
}
