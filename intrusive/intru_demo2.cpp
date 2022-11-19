#include <iostream>
// #include <boost/smart_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <unistd.h>
#include <vector>
#include <atomic>
#include <chrono>
#include <ctime>
#include <list>

using namespace std::chrono;
struct count_data;
struct count_data2;
typedef boost::intrusive_ptr<count_data> counted_ptr;

struct count_data
{
  // boost::intrusive_ptr<count_data2> in2;
  //  int m_count = 0;
  std::atomic<int> m_count {0};
// other funtion or data
  ~count_data() {
    std::cout << " ~count_data " << std::endl;
  }
};
// struct count_data2
// {
//   int m_count = 0;
//   //std::atomic<int> m_count {0};
//   // other funtion or data
//   boost::intrusive_ptr<count_data> in1;
//   ~count_data2() {
//     std::cout << " ~count_data2 " << std::endl;
//   }
// };
// 下面两个函数是内置的，只需要填写计算变量++/--
void intrusive_ptr_add_ref(count_data *p) {
  std::cout << " count_data count ++ brefore " <<p->m_count << std::endl;
  std::atomic_fetch_add(&p->m_count, 1);
  //p->m_count++;
}

void intrusive_ptr_release(count_data *p) {
  std::cout << " count_data count -- brefore " <<p->m_count.load() << std::endl;
  //if (--p->m_count == 0) {
  //  std::cout << " count_data count == 0" << std::endl;
  //  //delete p;
  //}
  std::atomic_fetch_sub(&p->m_count, 1);
}

// void intrusive_ptr_add_ref(count_data2 *p) {
//   ++p->m_count;
// }

// void intrusive_ptr_release(count_data2 *p) {
//   std::cout << " count_data2 count -- brefore " <<p->m_count << std::endl;
//   if (--p->m_count == 0) {
//     std::cout << " count_data2 count == 0" << std::endl;
//     //delete p;
//   }
// }


int main(int argc, char *argv[])
{
  typedef boost::intrusive_ptr<count_data> count_ref;
  count_data* cd = new count_data;
  count_ref c(cd);
  count_ref d(cd);
  std::cout << c->m_count << " cd " << cd << " c " << c << " d " << d.get() << std::endl;

  // std::list<std::list<count_ref>> test_refs;
  // test_refs.emplace_back(1, c);
  // for (auto &e : test_refs) {
  //   for (auto &i : e) {
  //     std::cout << i->m_count << std::endl;
  //   }
  // }
  // std::cout << " before clean " << std::endl;
  // test_refs.clear();
  // std::cout << " after clean " << std::endl;
}
