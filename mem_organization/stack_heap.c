#include <stdlib.h>
#include <stdio.h>

void check(int depth) {
    char c;
    char *ptr = malloc(1);
    printf("stack at %p, heap at %p\n", &c, ptr);
    if (depth <= 0) return;
    check(depth-1);
}

int main() {
    check(10);
    return 0;
}
