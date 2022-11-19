#include <stack>
#include <iostream>

int main () {
  std::stack<int> m;

  int t = m.pop();
  std::cout << t << std::endl;
  return 0;
}
