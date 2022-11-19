#include <iostream>


struct Name {
  int name = 0;
  Name(int a) {
    name = a;
  }
};
int main() {
  Name name(2);
  std::cout << " name " << name.name << std::endl;
}
