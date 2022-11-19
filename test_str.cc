#include <string>
#include <iostream>

int main() {
  std::string str = "app";
  std::string str2;
  std::cout << "str2 empty " << str2.empty() << str2.substr(0, 10) << std::endl;
  str2 = str;
  std::cout << str2  << " " << std::endl;
  str.append("test");
  std::cout << str2  << " str:" << str << std::endl;
}
