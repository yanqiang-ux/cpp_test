//#include<iostream>
//#include <errno.h> 
//#include <stdio.h>
//#include <map>
//typedef unsigned   uint32_t;
//using namespace std;
//int test_string(string& name) {
//  name = "syq";
//}
//
//int main () {
//  int a = -111;
//  if ( a <= -ETIMEDOUT && a >= -EHOSTUNREACH ) {
//    cout<< "yes" <<endl;
//  }
//  uint32_t  g = (uint32_t)(-1);
//  cout << "-1 :" << g << endl;
//  map<int, string> missing_loc;
//  missing_loc.insert(pair<int, string>(0, "student_zero"));
//  missing_loc.erase(1);
//  int b = 1;
//  switch(b){
//    case 1:
//      cout << 1 <<endl;
//      break;
//    case 2:
//      cout << 2 <<endl;
//      break;
//    case 3:
//      cout << 3 <<endl;
//      break;
//  }
//  string u;
//  test_string(u);
//  cout << "u :" << u << endl;
//}
//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//    Test(int _m,int _t):_cm(_m),_ct(_t){}
//    void Kf() const
//    {
//        //++_cm; // 错误
//        ++_ct; // 正确
//        _dd++;
//    }
//private:
//    int _cm;
//    mutable int _ct;
//    int _dd = 0;
//};
// 
//int main(void)
//{
//    Test t(8,7);
//    return 0;
//}

// splicing lists
 
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
int main ()
 
{
 
  list<int> mylist1, mylist2;
 
  list<int>::iterator it, tmp_it;
 
  // set some initial values:
 
  for (int i=1; i<=4; i++)
 
     mylist1.push_back(i);      // mylist1: 1 2 3 4
 
  for (int i=1; i<=3; i++)
 
     mylist2.push_back(i*10);   // mylist2: 10 20 30
 
  it = mylist1.begin();
 
  ++it;                         // points to 2
 
  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
 
                                // mylist2 (empty)
 
                                // "it" still points to 2 (the 5th element)                                     
 
  cout << "\nmylist1 contains:";
 
  for (tmp_it=mylist1.begin(); tmp_it!=mylist1.end(); tmp_it++)
 
    cout << " " << *tmp_it;
  mylist2.splice (mylist2.begin(), mylist1, it);
 
                                // mylist1: 1 10 20 30 3 4
 
                                // mylist2: 2
 
                                // "it" is now invalid.
 
  it = mylist1.begin();
 
  advance(it,3);                // "it" points now to 30
 
 
  mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
 
                                // mylist1: 30 3 4 1 10 20
 
 
  cout << "\nmylist1 contains:";
 
  for (it=mylist1.begin(); it!=mylist1.end(); it++)
 
    cout << " " << *it;
 
 
  cout << " \nmylist2 contains:";
 
  for (it=mylist2.begin(); it!=mylist2.end(); it++)
 
    cout << " " << *it;
 
  cout << endl;
 
 
  list<string> dictionary, bword;
 
  dictionary.push_back("any");
 
  dictionary.push_back("angle");
 
  dictionary.push_back("ajust");
 
  dictionary.push_back("common");
 
  dictionary.push_back("cannon");
 
  dictionary.push_back("company");
 
  bword.push_back("blue");
 
  bword.push_back("banana");
 
  bword.push_back("break");
 
  list<string>::iterator its = dictionary.begin();
 
  for (int i = 0; i < 3; i++)
 
      its++;
 
 dictionary.splice(its, bword);
 
 copy(bword.begin(), bword.end(), ostream_iterator<string>(cout, "/n"));
 
 return 0;
 
}
