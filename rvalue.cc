#include <iostream>
using namespace std;


int main()
{
    int i=5;
    int j=6;
    int &r=i;
    void *pi,*pj;
    long *addr;
    long dis;
    pi=&i;
    cout<<pi<<endl;//i的地址
    pj=&j;
    cout<<pj<<endl;//j的地址
    dis=(long)pj-(long)pi;//地址差
    cout<<dis<<endl;
    addr=(long *)((long)pj+dis);//获得引用底层const指针，即lambda的地址
    (*addr)+=dis;//将r由指向i转向指向j
    r=10;
    cout<<i<<" "<<j<<endl;
}
