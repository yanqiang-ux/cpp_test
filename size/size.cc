#include<iostream> 
using namespace std;

class Parent{
public:
    void fun(){
        cout<<"Parent fun"<<endl;
    }
}; 

class Child : public Parent{
public:
    void fun(){
        cout<<"Child fun"<<endl;
    }
    int b;
    char a;
};

int main(){
    Parent p;
    Child ch;
    cout<<"Parent size : "<<sizeof(p)<<", Child size : "<<sizeof(ch) <<endl;
    cout << " sizeof size_t " << sizeof(size_t) << " name " << sizeof(int) << endl;
    return 0;
}
