#include<iostream>
using namespace std;
class A{
  public:
    A(){};
    A(A & a){
      cout<<"Copy constructor called"<<endl;
    }
    A(A&& a)
  {
    cout << "Move Constructor" << endl;
  }
};

void Func(const A& a){ }

int main(){
  A a;
  Func(a);
  return 0;
}
