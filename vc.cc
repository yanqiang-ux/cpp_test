#include <vector>
#include <thread>

#include <iostream>

class Name {
   public:
	   std::vector<std::thread> threads;
	   int age = 0;
	   Name() {
	     age = 0;
	   }
	   void set_name(int a) {
             std::cout << " set name " << a << std::endl;
	     age = a;
	   }
	   void run_ths() {
             int a; 
	     for (int i = 0; i < 10; i ++) {
	       //threads.emplace_back(&Name::set_name, this, i);
	       threads.emplace_back(&Name::set_name, this, i);
	     }
	     for (auto& th : threads) th.join();
	   }

};

int main() {
  Name na;
  na.run_ths();
  return 0;
}
