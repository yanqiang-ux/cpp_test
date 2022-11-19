#include <boost/lockfree/stack.hpp>
#include <iostream>
#include <stack>
#include <time.h>

int main () {
  boost::lockfree::stack<int, boost::lockfree::fixed_sized<true> > m_stack(65530);
  std::stack<int> stack2;
  clock_t start1, end1;

  int t = 0;
  start1=clock();
  for (int k = 0; k  < 1; k ++) {
    for (int i = 0; i < 65530; i++) {
      m_stack.push(i);
    }

    for (int i = 0; i < 65530; i++) {
      m_stack.pop(t);
    }
  }
  end1=clock();
  double runtime =(double) (end1 - start1);
  std::cout << " t " << runtime << std::endl;

  start1=clock();
  for (int j = 0; j < 1 ; j++) {
    for (int i = 0; i < 65530; i++) {
      stack2.push(i);
    }

    for (int i = 0; i < 65530; i++) {
      stack2.pop();
    }
  }
  end1=clock();
  runtime =(double) (end1 - start1);
  std::cout << " t " << runtime << std::endl;

}
