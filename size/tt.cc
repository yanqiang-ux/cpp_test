#include <iostream>
#include <string>

int main() {
  std::string te;
  for (int i = 0; i < 2053; i++) {
    std::string tt = "s"+std::to_string(i);
    te.append(tt);
  }

  std::cout << "test size " << te.size() << std::endl;
}
