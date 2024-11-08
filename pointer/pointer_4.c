#include <stdio.h>

int main() {
  int number = 10, *ptr = &number;

  printf("O valor de number eh %d\n", *ptr);
  printf("O endereco de number eh %p\n", ptr);
  return 0;
}
