#include  <iostream>
#include  <unistd.h>

class Name {
  int a = 0;
  int c = 0;
  public:
  virtual void test() {
    std::cout << "test Name" << std::endl;
  };
  virtual ~Name () {}
};

class N1: public Name {
  int b =1;
  void test() override {
    std::cout << "test N1" << std::endl;
  }
  public:
  virtual ~N1() {}
};

int main() {
  Name na = Name();
  std::cout << sizeof(Name) <<  " " << sizeof(na) << std::endl;
  N1 n1 = N1();
  while(true) {
    sleep(1);
  }
}
