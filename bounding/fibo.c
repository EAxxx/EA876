
#include <stdio.h>
#include <pthread.h>

#include "cronometro.h"


int fibo(int N) {
  if (N<=2) return 1;
  else return fibo(N-1) + fibo(N-2);
}


int main () {
  int N = 40;
  fibo(N);
  return 0;
}
