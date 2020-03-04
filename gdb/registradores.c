
int main() {
  asm("mov $1, %rax");
  asm("mov $2, %rax");

  asm("push %rax");
  asm("pop %rax");
  return 0;
}
