#include <iostream>
#include <unistd.h>
using namespace std;

class Super{
public:
    Super(){
        cout<<"Super construction"<<endl;
    }
    virtual void fun(){
        cout<<"Super fun"<<endl;
    }
};

//class Parent : virtual public Super{
class Parent : public Super{
public:
     Parent(){
         cout<<"Parent construction"<<endl;
     }
}; 

class Father : public Super{
public:
      Father(){
          cout<<"Father construction"<<endl;
      }
};

class Child : public Parent, public Father{
public:
    virtual void hjzgg(){
        cout<<"呵呵"<<endl;
    }
    char ch[5];
};

int main(){
    Child ch;
    ch.Parent::fun();
    cout<<"Parent size : "<<sizeof(Parent)<<", Child size : "<<sizeof(Child) <<endl;
    while(1)
      sleep(1);
    return 0;
}
