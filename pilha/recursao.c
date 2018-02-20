
int recursao(int N) {
  return recursao(N-1);
}

int main() {
  recursao(4);
  return 0;
}
