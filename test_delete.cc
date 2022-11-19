#include <iostream>

struct Context {
};

int main() {
  Context *cbs[2];
  cbs[0] = cbs[1] = NULL;
  delete cbs[0];

}

