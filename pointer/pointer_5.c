#include <stdio.h>

float average(int numbers[], int size);

int main() {
  int numbers[] = {1, 5, 7, 3, 9};
  float result;

  result = average(numbers, 5);

  printf("The average of the array is %.2f\n", result);

  return 0;
}

float average(int numbers[], int size) {
  int sum = 0;

  for (int i = 0; i < size; ++i) {
    sum += numbers[i];
  }

  return (float) sum / size;
}
