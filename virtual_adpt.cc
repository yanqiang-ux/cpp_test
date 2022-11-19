#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class A
{
public:
    int _a;
};

class B : public A
{
public:
    int _b;
virtual void tbf(){};
};

class C :  public A
{
public:
    int _c;
virtual void tcf(){};
};

class D : public B, public C
{
public:
    int _d;
};


int  main()
{
    D d;
    d.B::_a = 1;  //添加域作用限定符指向修改_a
    d.C::_a = 2;  //同理
    
    B b;

    cout<<sizeof(D)<<endl;
    cout<<sizeof(B)<<endl;
    while (1){
      sleep(1);
    }
}

