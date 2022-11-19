#include<set>
#include<iostream>
using namespace std;

int main() {
  set<int> it = {1,2,3,4};
  for (auto i : it) {
   cout << i << endl;
   it.erase(i);
  }
  cout << it.size() << endl;
  return 0;
}
