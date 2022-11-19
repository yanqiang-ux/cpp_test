#include <iostream>
using namespace std;


class A 
{
  public:
    virtual void foo() { cout << "A" << endl; }
};

class B : public A 
{
  public:
    void foo() override { cout << "B" << endl; }
};

class C : public B 
{
  public:
    void foo() override { cout << "C" << endl; }
};

int main() 
{
  A *a = new A;
  B *b = new B;
  C *c = new C;
  a->foo(); //A
  b->foo(); //B
  c->foo(); //C

  A *ab = new B;
  A *ac = new C;
  B *bc = new C;
  ab->foo(); //B
  ac->foo(); //C, why?
  bc->foo();
  return 0;
}
