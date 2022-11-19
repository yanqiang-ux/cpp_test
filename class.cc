#include <iostream>

using namespace std;
struct CTestA
{
  public:
    CTestA(){cout<<"CTestA()\n";}
    ~CTestA(){cout<<"~CTestA()\n";}
};
 
 
struct CTestB
{
  public:
    CTestA * ca;
    CTestB(){cout<<"CTestB()\n";}
    //~CTestB()
    //{
    //  cout<<"~CTestB()\n";
    //  delete ca;
    //}
};
 
 
int main()
{
  {
    CTestA *a = new CTestA();
    CTestB b;
    b.ca = a;
  }
  std::cout << " end " << std::endl;
  return 0;
}

