#include <iostream>
#include <vector>
#define unlikely(x)     __builtin_expect((x),0)
using namespace std;

int main (){
  vector<int> name(10);
  if (unlikely(name.empty())) {
    cout << "empty" << endl;
  } else {
    cout << " !empty " << endl;
  }
}
