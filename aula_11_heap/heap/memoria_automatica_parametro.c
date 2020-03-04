
void func(int a[]) {
  a[0] = 1;
}

int main() {
  int a[50000];
  for (int i=0; i<900000; i++) {
    func(a);
  }
}
