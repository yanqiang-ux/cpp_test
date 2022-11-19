#include <boost/intrusive/list.hpp>
#include <vector>
#include <iostream>

using namespace boost::intrusive;

class MyClass : public list_base_hook<>
{
  public:
  int int_;

  list_member_hook<> member_hook_;

  MyClass(int i) :  int_(i)  {}
};

//Define a list that will store MyClass using the base hook
typedef list<MyClass> BaseList;
//
////Define a list that will store MyClass using the member hook
typedef member_hook
< MyClass, list_member_hook<>, &MyClass::member_hook_> MemberOption;
typedef list<MyClass, MemberOption> MemberList;
//
int main()
{
  typedef std::vector<MyClass>::iterator VectIt;

  //Create several MyClass objects, each one with a different value
  std::vector<MyClass> values;
  for(int i = 0; i < 10; ++i)  values.push_back(MyClass(i));

  BaseList baselist;
  MemberList memberlist;

  //Now insert them in the reverse order in the base hook list
  for(VectIt it(values.begin()), itend(values.end())
      ; it != itend  ; ++it){
    baselist.push_back(*it);
  }

  /* std::vector<list<MyClass, MemberOption>::iterator> it_list; */

  auto rm_it = baselist.begin();
  for (auto it = ++rm_it; it != baselist.end(); ++it) {
    std::cout << *&(it) << " " << it->int_ << std::endl;
    if (it->int_ % 3 == 0) {
      baselist.erase(rm_it);
      rm_it = it;
    }
  }

  for (auto it = baselist.begin(); it != baselist.end(); ++it) {
    std::cout <<  (it) << " " << it->int_ << std::endl;
  }

  //Now insert them in the same order as in vector in the member hook list
  for(VectIt it(values.begin()), itend(values.end()); it != itend; ++it)
    memberlist.push_back(*it);

  //Now test lists
  {
    BaseList::reverse_iterator rbit(baselist.rbegin());
    MemberList::iterator mit(memberlist.begin());
    VectIt  it(values.begin()), itend(values.end());

    //Test the objects inserted in the base hook list
    for(; it != itend; ++it, ++rbit)
      if(&*rbit != &*it)   return 1;

    //Test the objects inserted in the member hook list
    for(it = values.begin(); it != itend; ++it, ++mit)
      if(&*mit != &*it)    return 1;
  }

  return 0;
}
