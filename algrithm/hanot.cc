#include <iostream>

using namespace std;

void move(int &count) {
  count++;
  cout << " move" << endl;
}

int hanota(int n, char po1, char pol2, int pol3, int &count) {
  if (n == 1) {
    cout << " done moving A -> C times: " << endl;
    move(count);
    return 0;
  }
  hanota(n-1, 'A', 'B', 'C', count);
  move(count);
  hanota(n-1, 'B', 'C', 'B', count);
}

int main () {
  int n  =0;
  cout << "pls iput numbers:" << endl;
  cin >> n;
  int count = 0;
  hanota(n, 'A', 'B', 'C', count);
  cout << " total:" << count << endl;
  return 0;
}
