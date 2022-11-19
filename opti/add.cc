#include <iostream>

int a, b = 0;
int add() {
  return a++;
}

int add2() {
  int c = b++;
  return c;
}

int main() {
  std::cout << add() << std::endl;
  std::cout << add2() << std::endl;
  char name[90];
  std::cin >> name;
}
