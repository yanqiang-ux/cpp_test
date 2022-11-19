#include <iostream>
#include <set>

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow,itup;

  for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
  myset.erase(myset.find(60));

  itlow=myset.lower_bound (60);                //       ^
  itup=myset.upper_bound (60);                 //                   ^

  //myset.erase(itlow,itup);                     // 10 20 70 80 90
  std::cout << " " << *itlow << " " << *itup << " " << (itlow == itup)  << std::endl;
  if (itlow != myset.begin()) {
    std::cout << " before:" << *(--itlow) << std::endl;
  }
  std::cout << "myset contains:";
  for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  for (auto i = myset.begin(); i != myset.end(); i++) {
    std::cout << *i << std::endl;
  }
  return 0;
}
