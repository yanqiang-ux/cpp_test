#include <iostream>
class TT {
  public:
    int count = 0;

  TT & operator=(TT && r){
    std::cout << " = &&" << std::endl;
  }

  TT & operator=(const TT & r){
    std::cout << " = const &" << std::endl;
  }

  TT & operator=(TT& r){
    std::cout << " = &" << std::endl;
  }

  TT & operator=(const TT&& r){
    std::cout << " = const &&" << std::endl;
  }

  TT(int a): count(a) {
    std::cout << " a construct" << std::endl;
  }

  TT(): count(0) {
    std::cout << " zero construct" << std::endl;
  }
};

int main () {
  TT t1, t2;
  std::cout << " ====================" <<std::endl;
  t1 = TT(1);
  std::cout << " ====================" <<std::endl;
  t2 = t1;
}
