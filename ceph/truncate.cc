#include <iostream>
#include <string>
#include <vector>

int main() {
  //const std::string link_path = "../../t12_1";
  const std::string link_path = "/../../t12_1";
  uint16_t path_fields_len[1000];
  int num_fields = 0;
  int pos = 0;
  std::cout << " link_path " << link_path << std::endl;
  int end, begin = 0;
  if (link_path[0] == '/') {
    begin = 1;
    pos = 1;
  }
  while (true) {
    std::cout << " link_path " << link_path  << "degin " << begin << std::endl;
    end = link_path.find('/', begin);
    //  we already ensure the last char is not '/'
    if (end == std::string::npos) {
      path_fields_len[num_fields++] = link_path.size() - begin;
      break;
    }
    uint16_t path_len = end - begin;
    if (path_len == 0) {
      return -EINVAL;
    }
    path_fields_len[num_fields++] = path_len;
    if (end == link_path.size() - 1) {
      break;
    }
    begin = end + 1;
  }
  std::cout << " end !!!!! link_path " << link_path << std::endl;
  int tmp_mark = 0;
  std::vector<std::string> build_path;
  bool insert = false;
  bool changed = false;
  for (int i = 0; i < num_fields; ++i) {
    std::cout << " i " << i << std::endl;
    std::string filename(&link_path[pos], path_fields_len[i]);
    if (filename == "..") {
      --tmp_mark;
    }
    if (filename != ".") {
      ++tmp_mark;
    }
    std::cout << " filename " << filename << " .. " << (filename == "..") << " " << filename.size() <<std::endl;
    build_path.push_back(filename);
    pos += path_fields_len[i] + 1;
  }

}
