#include <iostream>
#include <map>
#include <assert.h>
#include <set>

using namespace std;

int main() {

  std::map<std::set<int>, int> mmap;

  std::map <uint16_t, uint16_t> test00;
  test00.emplace(1,1);
  auto it = test00.end();
  cout << " test0 end :" << it->first << " it " << test00.begin()->first << " tt " << test00.end()->first << endl;

map <string, int> test, test2;

map<string, int>::iterator j = test.begin();
while (j != test.end()) {
  cout << "test" << j->first << endl;
}
test["a"] = 1;
test["b"] = 1;
test["c"] = 1;
test["d"] = 1;
test["e"] = 1;

test2 = test;
test2["a"] = 2;
//map<string, int>::iterator i = test.begin();
//cout << i->first << endl;
//i++;
//cout << i->first << endl;
//
//assert(1 || test.empty());
//
for (auto i : test) {
   cout << "test" << i.first << " " << i.second << endl;
   //test.erase(i.first);
}
for (auto i : test2) {
   cout << "test2 " << i.first << " " << i.second << endl;
   //test.erase(i.first);
}
cout << " size:" << test.size() << endl;
}
