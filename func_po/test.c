
int CMP_(int x, int y) {
  if (x > y) {
    return 1;
  }
  return 0;
}


void sort(int a[], int n, int (*cmp)(int, int)) {
   for (int i = 0; i < n - 1; i++) {
      for (int j = i+1; j < n; j++) {
        if (cmp(a[i], a[j]))
          return;
      }
   }
}

int main() {

  int a[6] = {8, 2, 1, 3, 4, 5};
  sort(a, 6, CMP_);
  return 0;
}
