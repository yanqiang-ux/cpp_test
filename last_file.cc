#include <iostream>

int get_last_file(const std::string& full_path, std::string* last_file) {
  std::string path = full_path;
  size_t l_pos = path.find_last_of("/");
  while ((l_pos != std::string::npos) && path.size()) {
    std::string last_name;
    if (l_pos+1 < path.size()) {
      last_name = path.substr(l_pos+1);
      if ((last_name != "/") && !last_name.empty()) {
        *last_file = last_name;
        break;
      }
    }
    path = path.substr(0, l_pos - 0);
    std::cout << " path:" << path << std::endl;
    l_pos = path.find_last_of("/");
  }
  size_t s_pos = path.find(".snap");
  if ((s_pos != std::string::npos) && (s_pos != l_pos + 1)) {
    std::cout << "error snap dir" << std::endl;
  }
  return 0;
}

int main() {
  std::string name = "/t1//.snap/snap1" ;
  std::string last_file;
  get_last_file(name, &last_file);
  std::cout << " last_file:" << last_file << std::endl;
}
