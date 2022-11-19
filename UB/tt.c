#include<vector>
#include<iostream>

struct na {
 int a = 0;
 int b = 0;
 na(){
   std::cout << " new na " << std::endl;
 }
};

int main() {
  std::vector<na> nas;
  nas.emplace_back(na());
  na &n = nas[0];
  n.a=1;
  n.b=2;
  std::cout << nas[0].a << nas[0].b << std::endl;
}
