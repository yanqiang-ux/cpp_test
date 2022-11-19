#include <boost/variant.hpp>
#include <iostream>

int main() {
boost::variant <int, std::string , double> u;
u = 4;
int i = boost:: get<bool>(u);
std::cout << "int : " << i << std ::endl;
}
