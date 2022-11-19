#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int> youmap;
  std::map<char,int>::iterator itlow,itup;
  std::map<char,int>::iterator it_test;
  std::map<char,int>::iterator it_test2;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  youmap['e']=100;


  it_test = mymap.lower_bound ('f');
  std::cout << (it_test == mymap.begin()) << " " << (it_test == mymap.end()) << std::endl;
  std::cout << " youmap size :" << youmap.size() << std::endl;
  it_test2 = youmap.lower_bound('f');
  std::cout << (it_test2 == youmap.begin()) << " " << (it_test2 == youmap.end()) << std::endl;
  std::cout << " it_test2 key:" << it_test2->first << std::endl;

  
  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
