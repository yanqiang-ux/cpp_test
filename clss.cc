#include <iostream>
using namespace std;
class CreateAndDestroy{ 
    public: 
        CreateAndDestroy(int n) { no=n; cout<<"Object "<<no << "created!"<< endl; } 
        ~CreateAndDestroy() { cout<<"Object "<<no << "destructed!"<<endl; } 
    private:
        int no; 
}; 
CreateAndDestroy one(1); 
int main() { 
    CreateAndDestroy*ptr; 
    CreateAndDestroy two(2);
    { 
        CreateAndDestroy three(3);
        ptr=new CreateAndDestroy(4);
        static CreateAndDestroy five(5);
    } 
    delete ptr;
    return 0; 
}
