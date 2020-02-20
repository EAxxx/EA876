#include <stdio.h>

int main() {
  int a[1000];
  
  for (int i=0; i<10000; i++)
    a[i] = i;

  return 0;
}
