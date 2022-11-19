#include <iostream>

class Num {
  public:
  int id = 0;
  int ids = 0;
  Num (int id_, int ids_) {
    id = id_;
    ids = ids_;
  }
  // friend bool operator==(const Num& l, const Num& r) {
  //   std::cout << "test == " << std::endl;
  //   return true;
  // }

  friend bool operator==(const Num& l, const Num& r) {
    std::cout << "test == " << std::endl;
    return true;
  }
};

template <typename T>
struct always_false {
  using value = std::true_type;
};

template <typename T>
inline bool operator==(const Num &lhs, const T&) {
  static_assert(always_false<T>::value::value, "Do not compare to get_max()");
  std::cout << "uuu" << std::endl;
  return lhs.id == 1;
}

class UI {
  public:
  int id;
  bool get_max() {
    return true;
  }
};

int main() {
  Num n1 = Num(1, 2);
  Num n2 = Num(2, 3);
  UI ui = UI();

  std::cout << (n1 == n2) << std::endl;
  std::cout << (n1 == ui) << std::endl;
}
