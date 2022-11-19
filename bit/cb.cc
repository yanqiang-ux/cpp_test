// #include <type_traits>
#include <iostream>

uint32_t cbits(uint32_t a) {
  if (a == 0) {
    return 0;
  }
  std::cout << " size " << sizeof(a) << " bt " << __builtin_clz(a);
  return (sizeof(a)*8) - __builtin_clz(a);
}

int main() {
  uint32_t b = 12;
  uint32_t c = cbits(b-1);
  std::cout << " c " << c << std::endl;
  uint32_t t = (1 << c);
  std::cout << " cb " << t << std::endl;
}
