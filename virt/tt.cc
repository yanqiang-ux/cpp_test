#include <iostream>
using namespace std;
class A
{
    int i = 10;
    int ia = 100;
    void func() {}
    virtual void run() { cout << "A::run()" << endl; }
    virtual void run1() { cout << "A::run1()" << endl; }
    virtual void run2() { cout << "A::run2()" << endl; }
};
class B : public A
{
    virtual void run() { cout << "B::run()" << endl; }
    virtual void run1() { cout << "B::run1()" << endl; }
};
class C :public A
{
    virtual void run() { cout << "C::run()" << endl; }
    virtual void run1() { cout << "C::run1()" << endl; }
    virtual void run3() { cout << "C::run3()" << endl; }
};
class D :/*virtual*/ public A
{
    virtual void run() { cout << "D::run()" << endl; }
    virtual void run1() { cout << "D::run1()" << endl; }
    virtual void run2() { cout << "D::run2()" << endl; }
    virtual void run3() { cout << "D::run3()" << endl; }
};

int test()
{
    cout << sizeof(A) << endl
         << sizeof(B) << endl
         << sizeof(C) << endl
         << sizeof(D) << endl;
    cout << sizeof(long long) << endl;
    //A * pA = new D;
    D d;
    //d.run();
 
    typedef void(*Function)(void);
 
    int ** pVtable = (int **)&d;
 
#if 0
    int * pVtable = (int*)&d;
    int vtaleAdress = *pVtable;
 
    int * ppVtable = (int*)vtaleAdress;
    int func1 = *ppVtable;
 
    Function f1 = (Function)func1;
    f1()
#endif
    //pVtable[0][0]
 
    for (int idx = 0; pVtable[0][idx] != NULL; ++idx)
    {
        Function f = (Function)pVtable[0][idx];
        f();
    }
 
    //cout << (int)pVtable[1] << endl;
    //cout << (int)pVtable[2] << endl;
 
    return 0;
}
 
int main(void)
{
    test();
    return 0;
}
