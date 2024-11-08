#include <stdio.h>

void incrementar(int *number);

int main() {
  int number = 0;

  incrementar(&number);

  printf("O numero eh %d\n", number);

  return 0;
}

void incrementar(int *number) {
  ++(*number);
}
