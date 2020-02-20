
#include <stdio.h>


void func(int N) {
  double a;
  a = 100;
  if (N<10) func(N+1);
}

int main() {
  func(0);
  return 0;
}
