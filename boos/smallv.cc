#include <iostream>
#include <boost/container/small_vector.hpp>

int main()
{
  auto vec = boost::container::small_vector<int, 3> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  

  for (const auto& num : vec)
  {
    std::cout << num <<
      "Index: " << num <<
      " Distance from vec[0]: " << (long)&num - (long)&vec[0] <<
      " Distance from vec: " << (long)&num - (long)&vec << "\n";
  }
  vec.clear();

  for (const auto& num : vec)
  {
    std::cout << num <<
      "Index: " << num <<
      " Distance from vec[0]: " << (long)&num - (long)&vec[0] <<
      " Distance from vec: " << (long)&num - (long)&vec << "\n";
  }
}
