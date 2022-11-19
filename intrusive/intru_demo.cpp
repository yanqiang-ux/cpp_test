#include <iostream>
// #include <boost/smart_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <unistd.h>
#include <vector>
#include <atomic>
#include <chrono>
#include <ctime>

using namespace std::chrono;
struct count_data;
struct count_data2;
typedef boost::intrusive_ptr<count_data> counted_ptr;

struct count_data
{
  boost::intrusive_ptr<count_data2> in2;
  //  int m_count = 0;
  std::atomic<int> m_count {0};
// other funtion or data
  ~count_data() {
    std::cout << " ~count_data " << std::endl;
  }
};
struct count_data2
{
  int m_count = 0;
  //std::atomic<int> m_count {0};
  // other funtion or data
  boost::intrusive_ptr<count_data> in1;
  ~count_data2() {
    std::cout << " ~count_data2 " << std::endl;
  }
};
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

void intrusive_ptr_add_ref(count_data2 *p) {
  ++p->m_count;
}

void intrusive_ptr_release(count_data2 *p) {
  std::cout << " count_data2 count -- brefore " <<p->m_count << std::endl;
  if (--p->m_count == 0) {
    std::cout << " count_data2 count == 0" << std::endl;
    //delete p;
  }
}

std::vector<count_data*> cs;
std::vector<count_data2*> cs2;
int loop() {
  count_data* tc = new count_data;
  cs.push_back(tc);
  counted_ptr p(tc);
  assert(p);
  std::cout << " p addr " << p << std::endl;
  assert(p->m_count == 1); // p拥有
  counted_ptr p2(p);
  std::cout << " p addr " << p2 << std::endl;
  assert(p->m_count == 2); // 指针拷贝构造，p和p2同时拥有
  //counted_ptr weak_p(p.get(), false); // 值为false,相当于weak_ptr，只是一个观察者，不会增加引用计数
  //assert(weak_p->m_count == 2); // p和p2同时拥有,weak_p观察者
  //std::cout << "weak_p->m_count " << weak_p->m_count << std::endl;
  //counted_ptr test_p = weak_p;
  //std::cout << " test_p " << test_p->m_count << std::endl;
  count_data2* tc2 = new count_data2;
  cs2.push_back(tc2);
  boost::intrusive_ptr<count_data2> c2(tc2);
  c2->in1 = p;
  //p->in2(c2.get(), false);
  p->in2 = c2;

  std::cout << " c2 " << c2->m_count << " addr " << c2 << std::endl;
  //c2->m_count--;
  std::cout << " c2 " << c2->m_count << " addr " << c2 << std::endl;
  std::cout << " p " << p->m_count << " addr " << p<< std::endl;
}

counted_ptr get_intru(){
 count_data* tc = new count_data;
 cs.push_back(tc);
 //tc->m_count++;
 //counted_ptr tt(tc, true);
 return counted_ptr(tc, true);
}

counted_ptr get_intru2() {
  counted_ptr cp = get_intru();
  std::cout << " cp count " << cp->m_count << std::endl;
  return counted_ptr(cp);
}

class TT {
public:
  counted_ptr cp;
  counted_ptr get_intru() {
    return cp;
  }

  counted_ptr get_intru2() {
    return counted_ptr(cp.get(), false);
  }
};

int main(int argc, char *argv[])
{
  //loop();
  //usleep(100000);
  //counted_ptr tt = get_intru2();
  //std::cout << " tt count " << tt->m_count << std::endl;
  //counted_ptr tt = get_intru();
  //std::cout << " count " << tt->m_count << std::endl;
  //counted_ptr tt1 = tt;
  //std::cout << " count " << tt->m_count << std::endl;
  //counted_ptr tt2(tt);
  //std::cout << " count " << tt->m_count << std::endl;
  //counted_ptr tt3 = tt;
  //std::cout << " count " << tt->m_count << std::endl;
  //counted_ptr tt4 = std::move(tt3);
  //std::cout << " count " << tt->m_count << std::endl;
  //counted_ptr tt5 = std::move(tt2);
  //std::cout << " count " << tt->m_count << std::endl;
  //while(true) {
  // usleep(100000);
  //}
  //test   begin
  //TT *tt = new TT();
  //tt->cp = get_intru();
  //std::cout << " 1 tt.cp " << tt->cp->m_count << std::endl;
  //{
  //  counted_ptr i1 = tt->get_intru();
  //}
  //std::cout << " 2 tt.cp " << tt->cp->m_count << std::endl;
  //{
  //  counted_ptr i2 = tt->get_intru2();
  //}
  //std::cout << " 3 tt.cp " << tt->cp->m_count << std::endl;
  //std::cout << " 1 tt.cp " << tt->cp->m_count << std::endl;
  //{
  //  auto start = system_clock::now();
  //  for (int i = 0; i < 1000000; i++)
  //    counted_ptr t0 = tt->get_intru();
  //  auto end   = system_clock::now();
  //  auto duration = duration_cast<microseconds>(end - start);
  //  std::cout << "cost " << double(duration.count()) * microseconds::period::num / microseconds::period::den << std::endl; 
  //}
  //std::cout << " 2 tt.cp " << tt->cp->m_count << std::endl;
  //{
  //  auto start = system_clock::now();
  //  for (int i = 0; i < 1000000; i++)
  //    counted_ptr t1 = tt->get_intru2();
  //  auto end   = system_clock::now();
  //  auto duration = duration_cast<microseconds>(end - start);
  //  std::cout << "cost " << double(duration.count()) * microseconds::period::num / microseconds::period::den << std::endl;
  //}
  //std::cout << " 3 tt.cp " << tt->cp->m_count << std::endl;
  count_data* tc = new count_data;
  counted_ptr td = tc;
  counted_ptr te = tc;
  counted_ptr tf = te;
  std::cout << "td " << td << " te " << te << " tf " << tf << " tc " << tc << std::endl;
  delete tc;
}
