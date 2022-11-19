#include <iostream>
#include<bitset>

int main() {
  int a = -1;
  int m = a % 2;
  std::cout << "osize " << sizeof(a) << (a % 2 == 1) << " " << (a % 2 != 0) << " " << std::bitset<32>(a) << std::endl;
  std::cout << " m " << m << std::endl;
}
