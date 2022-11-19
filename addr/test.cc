#include <iostream>

int main () {
  int a = 0x1234;
  char* p = (char*)(&a);
  std::cout << *p << std::endl;
  std::cout << *(++p) << std::endl;
  std::cout << *(++p) << std::endl;
  std::cout << *(++p) << std::endl;
}
