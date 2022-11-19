// CPP program to demonstrate multithreading 
// using three different callables. 
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <chrono>
using namespace std;

mutex mtx;
condition_variable cv;

struct CB {
  atomic<int> count {0};
  function<int(int)> func;
} CB_t;

struct CB cb;

// A dummy function
void foo(int Z)
{
  for (int i = 0; i < Z; i++) {
    cout << "Thread using function"
      " pointer as callable\n";
  }
   //std::unique_lock <std::mutex> lck(mtx);
   //cv.wait(lck);
   cb.count++;
   cb.func(2);
}

// A callable object
class thread_obj {
  public:
    void operator()(int x)
    {
      for (int i = 0; i < x; i++)
        cout << "Thread using function"
          " object as callable\n";
      //std::unique_lock <std::mutex> lck(mtx);
      //cv.notify_all();
    }
};

int test_func (int a ) {
  cout << __func__ << " test cb 1 a " << a << endl;
  cb.func = [](int a ) ->int {
    cout << "change CB funci " << a << endl;
  };
  std::this_thread::sleep_for(std::chrono::seconds(2));
  cb.func(a);
}

int main()
{
  cout << "Threads 1 and 2 and 3 "
       << "operating independently" << endl;
  cb.func = test_func;
  // This thread is launched by using
  // function pointer as callable
  thread th1(foo, 3);

  // This thread is launched by using
  // function object as callable
  thread th2(thread_obj(), 3);

  // Define a Lambda Expression
  auto f = [](int x) ->int {
    for (int i = 0; i < x; i++)
      cout << "Thread using lambda"
        " expression as callable\n";
  };

  // This thread is launched by using
  // lamda expression as callable
  //thread th3(f, 3);

  // Wait for the threads to finish
  // Wait for thread t1 to finish
  th1.join();

  // Wait for thread t2 to finish
  th2.join();

  // Wait for thread t3 to finish
  //th3.join();

  return 0;
}

