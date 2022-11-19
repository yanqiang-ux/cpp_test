#include <iostream>
#include <string>

class Base {
  public:
  Base() {}
  ~Base() {}
  virtual std::string get_name() {
    return "BASE";
  }
  virtual int test() {
    return 1;
  }
};

class C : public Base {
  public:
  C() {}
  ~C() {}
  std::string get_name() override {
    return "C";
  }
};

int main() {
  Base *b = new C();
  std::cout << (b->get_name()) << std::endl;
}
