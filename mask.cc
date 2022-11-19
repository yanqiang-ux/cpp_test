#include <iostream>
#include <inttypes.h>
#include "rados/librados.hpp"
#include <bitset>
// typedef unsigned __int64     uint64_t;

int main () {
uint64_t a = 2305244849115037691;
std::cout << std::bitset<64>(a) << std::endl;
uint64_t b = 144115188077953024;
std::cout << std::bitset<64>(b) << std::endl;
std::cout << std::bitset<64>(a&b) << std::endl;
}
