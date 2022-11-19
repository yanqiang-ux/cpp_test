#include <iostream>
#include <unistd.h>
using namespace std;

class A
{
public:
    int _a;
};

class B : virtual public A
{
public:
    int _b;
virtual void test(){}
};

class C : virtual public A
{
public:
    int _c;
};

class D : public B, public C
{
public:
    int _d;
};

int  main()
{
  D d;
  d.C::_a = 2;  //同理
  d.B::_a = 1;  //添加域作用限定符指向修改_a
  B b; 

  cout << d._a << endl;
  cout<<sizeof(D)<<endl;
  cout<<sizeof(B)<<endl;
  while(1) {
  sleep(2);
  }
}
