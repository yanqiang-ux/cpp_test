#include <iostream>
#include <list>

int main() {

  std::list<int> ll, l2;

  for (int i = 0; i< 10; i++)
  ll.emplace_back(i);
  
  for (int j = 0; j < 6; j++) {
    l2.emplace_back(j);
  }
  
  ll.splice(ll.end(), l2);

  for (auto h : ll) {
    std::cout << h << std::endl;
  }
  // std::list<int>::iterator it, it2, it3, it1;

  // it3 = ll.begin();
  // while (it3 != ll.end()) {
  //   if (*it3 == 2) {
  //     it = it3;
  //   } else if (*it3 == 5) {
  //     it1 = it3;
  //   } else if (*it3 == 7) {
  //     it2 = it3;
  //   }
  //   ++it3;
  // }

  // ll.erase(it2);
  // ll.erase(it1);
  // ll.erase(it);

  // it3 = ll.begin();
  // while (it3 != ll.end()) {
  //   std::cout<< *it3 << " " <<  std::endl;
  //   ++it3;
  // }
}
