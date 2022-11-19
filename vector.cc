#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

int test(int *a) {
  *a = 7;
  assert(0);
}

int main ()
{
  //std::vector<int> tts;
  //tts.push_back(0);
  //tts.push_back(5);
  //std::vector<int>*tt2 = new std::vector<int>(4,0);
  //std::vector<int*> tt3;
  //int a = 3;
  //int b = 4;
  //tt3.push_back(&a);
  //tt3.push_back(&b);
  //std::cout << "tts:" << &tts << " tts0 " << &tts[0] << " tts1 " << &tts[1] << std::endl;
  //std::cout << " tt2 " << &tt2 << " " << tt2 << " tt20 " << &(*tt2)[0] << " tt21 " << &(*tt2)[1] << std::endl;
  //std::cout << " tt3 " << &tt3 << " tt20 " << &(tt3)[0] << " tt21 " << &(tt3)[1] << std::endl;
  //std::cout << " tt3 " << &tt3 << " tt20 " << (tt3)[0] << " tt21 " << (tt3)[1] << std::endl;
  //std::cout << " tt3 " << &tt3 << " tt20 " << *(tt3)[0] << " tt21 " << *(tt3)[1] << std::endl;
  int c = 6;
  //std::cout << " c " << &c << " " << &&c << " " << &&&&c << std::endl;

  // test(&c);
  std::vector<int> myvector;
  //std::set<int> myset;
  //// set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);
  //for (int i=1; i<=10; i++) myset.emplace(i);
  //
  for (std::vector<int>::iterator i = myvector.end(); i != myvector.begin();) {
    --i;
    std::cout << *i << std::endl;
    if (*i == 5) {
      i = myvector.erase(i);
      std::cout << "new i " << *i << std::endl;
      continue;
    }
  }

  for (std::vector<int>::reverse_iterator i = myvector.rbegin(); i != myvector.rend();) {
    std::cout << *i << std::endl;
    ++i;
  }
  //// erase the 6th element
  ////myvector.erase (myvector.begin()+5);
  ////for (std::vector<int>::iterator i = myvector.begin(); i != myvector.end();) {
  //    //if (*i == 6) {
  //    //  myvector.erase(i++);
  //    //} else {
  //    //  i++;    
  //    //}
  ////    myvector.erase(i);
  ////}
  //// erase the first 3 elements:
  ////myvector.erase (myvector.begin(),myvector.begin()+3);

  //for (auto i : myvector) {
  //  std::cout << i << std::endl;
  //}
  //for (auto i : myset) {
  //  std::cout << i << std::endl;
  //  myset.erase(i);
  //}
  //std::cout << "myvector contains:" << myvector.size() << std::endl;
  //std::cout << "myset contains:" << myset.size() << std::endl;
  //for (unsigned i=0; i<myvector.size(); ++i)
  //  std::cout << ' ' << myvector[i];
  //std::cout << '\n';

  return 0;
}
