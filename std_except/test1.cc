#include <iostream>
#include <thread>
#include <vector>
void thread_func() {
        std::cout << "thread_func start ..." << std::endl;
        std::vector<int> vec;
        //vec.push_back(1);
        //vec.push_back(2);
        std::cout << vec.at(1) << std::endl;
}
int main (void) {
   std::set_terminate([](){
       std::cout << "Unhandled exception\n" << std::flush;
       std::abort();
       });
   try {
     std::thread th1(thread_func);
     th1.join();
   } catch (...) {
     std::abort();
   }
   return 0;
}
