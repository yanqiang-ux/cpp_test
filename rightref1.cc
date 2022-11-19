#include <iostream>
using namespace std;
class Stack
{
public:
    // 构造
    Stack(int size = 1000) 
        :msize(size), mtop(0)
    {
        cout << "Stack(int) " << size << endl;
        mpstack = new int[size];
    }
        
    // 析构
    //~Stack()
    //{
    //    cout << "~Stack()" << endl;
    //    delete[]mpstack;
    //    mpstack = nullptr;
    //}
        
    // 拷贝构造
    //Stack(const Stack &src)
    //    :msize(src.msize), mtop(src.mtop)
    //{
    //    cout << "Stack(const Stack&)" << endl;
    //    mpstack = new int[src.msize];
    //    for (int i = 0; i < mtop; ++i) {
    //        mpstack[i] = src.mpstack[i];
    //    }
    //}
        
    //Stack(Stack src)
    //    :msize(src.msize), mtop(src.mtop)
    //{
    //    cout << "Stack(const Stack&)" << endl;
    //    mpstack = new int[src.msize];
    //    for (int i = 0; i < mtop; ++i) {
    //        mpstack[i] = src.mpstack[i];
    //    }
    //}
    // 赋值重载
    Stack& operator=(const Stack &src)
    {
        cout << "operator=" << endl;
        if (this == &src)
            return *this;

        delete[]mpstack;

        msize = src.msize;
        mtop = src.mtop;
        mpstack = new int[src.msize];
        for (int i = 0; i < mtop; ++i) {
            mpstack[i] = src.mpstack[i];
        }
        return *this;
    }

    int getSize() 
    {
        return msize;
    }
private:
    int *mpstack;
    int mtop;
    int msize;
};

//Stack GetStack(Stack &stack)
//{
//    //Stack tmp(stack.getSize());
//    Stack tmp(stack);
//    return tmp;
//}

Stack GetStack(Stack stack)
{
    cout << "in GetStack" << endl;
    Stack tmp(stack.getSize());
    //Stack tmp(stack);
    return tmp;
}

int main()
{
    Stack s;
    cout << " after init" << endl;
    s = GetStack(s);
    return 0;
}
