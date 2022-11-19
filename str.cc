#include <iostream>
#include <string>
using namespace std;

int carry() {
  int is [8];
  for (int i = 0; i < 16; i++) {
    is[i] = i;
  }
  return 0;
}

int main() {
  std::string name = "name";
  std::string cok1 = "";
  std::string cok2 = "";
  std::cout << " comp " << cok1.compare(cok2) << std::endl;
  // return carry();
 //string a = "1234567890";
//string a = "1234/.snap/.snap";
 //size_t pos = a.find("/.snap/");
 //pos = a.find_last_of("/");
 //cout << a.substr(0, pos) << " " << a.substr(pos+1) << endl;
 //pos = a.find(".snap", pos+7);
 //cout << a[pos] << endl;
 //string::iterator it = a.end() - 5;
 //cout << *it << (*(it -1) == '/') << endl;
 //string b = a.substr(it-a.begin(), 5);
 //std::cout << b << std::endl;
}
