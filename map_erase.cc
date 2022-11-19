#include <map>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main () {
map <int, int> test;
test.insert(make_pair(1, 1));
test.insert(make_pair(2, 2));
test.insert(make_pair(3, 3));
test.insert(make_pair(4, 4));
test.insert(make_pair(5, 5));
for (map<int, int>::iterator i = test.begin(); i != test.end();) {
  cout << " print:" << i->first << endl;
  if (i->first % 2 == 1) {
    test.erase(i++);
    continue;
  }
  cout << i->first << endl;
  i++;
}

vector<int> name;
name.push_back(1);
name.push_back(2);
name.push_back(3);
name.push_back(4);
name.push_back(5);

for (vector<int>:: iterator i = name.begin(); i < name.end();) {
  cout << " print:" << *i << endl;
  if ( *i % 2 == 1) {
    name.erase(i);
    continue;
  }
  cout << "leak:" << *i << endl;
  i++;
}

list<int> tl;
tl.push_back(1);
tl.push_back(2);
tl.push_back(3);
tl.push_back(4);
tl.push_back(5);
tl.push_back(6);
for (list<int>:: iterator i = tl.begin(); i != tl.end();) {
  cout << " print:" << *i << endl;
  if ( *i % 2 == 1) {
    tl.erase(i++);
    continue;
  }
  cout << "leak:" << *i << endl;
  i++;
}

return 0;
}
