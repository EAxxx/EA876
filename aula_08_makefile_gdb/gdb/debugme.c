
#define NUMERO_QUALQUER 99

int main() {
  int a[10];
  int b[10];
  for (int i=0; i<15; i++)
    a[i] = NUMERO_QUALQUER;

  if (b[0]==NUMERO_QUALQUER)
    b[0] = NUMERO_QUALQUER+1;

  return 0;
}
