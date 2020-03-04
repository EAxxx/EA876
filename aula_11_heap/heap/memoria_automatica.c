
void func() {
  int a;
  a = 1;
}

int main() {
  for (int i=0; i<900000; i++) {
    func();
  }
}
