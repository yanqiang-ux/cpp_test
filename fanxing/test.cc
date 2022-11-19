#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};
struct Node1 {
    int val;
};

struct Node2 {
    int bh;
};

class FX {

  public:
  template<typename T> 
    void tfunc(const T& t) {
      cout << " val " << t.val << endl;
    }

};

int main() {
  Node node;
  node.val = 1;

  Node1 no;
  no.val = 2;

  Node2 b;
  b.bh = 3;

  FX *f = new FX();
  f->tfunc(node);
}
