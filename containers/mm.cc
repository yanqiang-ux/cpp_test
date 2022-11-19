#include <iostream>
#include <map>
#include <assert.h>

int main() {
  std::map<int, int> *tmp;
  std::map<int, int> tm;

  tmp = &tm;
  tmp->emplace(1,1);
  std::cout << " " << tmp->size() << std::endl;
  for (auto rnt : *tmp) {
    std::cout << rnt.first << std::endl;
  }
  std::map<int, int> tm1;
  tmp = &tm1;
  for (auto rnt : *tmp) {
    std::cout << rnt.first << std::endl;
  }
}
