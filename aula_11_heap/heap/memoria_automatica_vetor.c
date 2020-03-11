
void func() {
  int a[50000];
  a[0] = 1;
}

int main() {
  for (int i=0; i<900000; i++) {
    func();
  }
}
