
#include <stdio.h>


int fibo(int N) {
  int a, b;
  if (N<=2) return 1;
  else {
    a = fibo(N-1);
    b = fibo(N-2);
    return a + b;
  }
}

int main() {
  int K = fibo(5);
  printf("fibo(5)=%d\n", K);
  return 0;
}
