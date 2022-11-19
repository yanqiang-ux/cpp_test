#include <rados/librados.h>
#include <rados/librados.hpp>
#include <iostream>
#include <string>

int main () {

  ceph::bufferlist bl;
  std::string error;
  char* fn = "./2m_zero";
  int r = bl.read_file(fn, &error);
  std::cout << "crc " << bl.crc32c(0) << std::endl;


}
