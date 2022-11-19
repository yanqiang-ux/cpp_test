#include <vector>
#include <thread>
#include <iostream>

void pri(int &a) {
  std::cout << a << std::endl;
}

int main () {
  std::vector<int> jobs {1, 2};

  for(auto &job : jobs) {
    auto fn = [&]() { std::cout << job << " addr " << &job << std::endl; };
    new std::thread([&]() { fn(); });

    // new std::thread(pri, std::ref(job));
  }
  int a;
  std::cin >> a;
}
