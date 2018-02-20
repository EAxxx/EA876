
int soma(int N) {
  return soma(N-1) + 1;
}

int main() {
  soma(4);
  return 0;

}
