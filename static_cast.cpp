#include <iostream>
using namespace std;

class A{
  public:
  A() {
    cout << " A()" << endl; 
  }  

  ~A() {
    cout << " ~ A " << endl;
  }
};

class B :public A{
  public:
  int b = 0;
  B(){
    cout << " B()" << endl;
  }

  ~B(){
    cout << " ~B()" << endl;
  }
};

int main() {
  B tb = B();
  A* pa = &tb;
  B* pb = static_cast<B *>(pa);
  pb->b = 1;
  cout << pb->b << " " << tb.b << endl;
}
