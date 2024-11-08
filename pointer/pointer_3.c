#include <stdio.h>

void change(int *n1, int *n2);

int main() {
  int number1 = 5, number2 = 10;

  printf("Number 1: %d ; Number 2: %d\n", number1, number2);

  change(&number1, &number2);

  printf("Number 1: %d ; Number 2: %d\n", number1, number2);

  return 0;
}

void change(int *n1, int *n2) {
  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}
