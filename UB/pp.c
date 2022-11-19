#include <iostream>

int main() {
  int i = 1;
  int b = (++i) + (--i);
  std::cout << "b " << b << std::endl;
}
