#include  <iostream>
#include  <unistd.h>

class Name {
  int a = 0;
};

class N1: public Name {
  int b =1;
};

int main() {
  Name na = Name();
  std::cout << sizeof(Name) <<  " " << sizeof(na) << std::endl;
  N1 n1 = N1();
  while(true) {
    sleep(1);
  }
}
