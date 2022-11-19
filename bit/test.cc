#include <iostream>
#include <bitset>
using namespace std;
int main() {
int a = 129;
int b = 126;
int t = (a - 128) >> 31;
int t2 = (b -  128) >> 31;
std::cout << " t1 " << bitset<32>(t) << " t2 " << bitset<32>(t2) << std::endl;
}
