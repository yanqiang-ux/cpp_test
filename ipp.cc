#include<iostream>

using namespace std;

int main() {
  //int i = 0;
  //for (int j = 0; j < 10; j++) {
  //  i = i++;
  //}
  int i =0, j = 0;
  i=2; 
  j = (++i)+(++i)+(++i);
  //j = (++i)+(++i);
  //j = (++i);
  cout << j << endl;
}
