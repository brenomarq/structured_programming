#include <stdio.h>

int soma_matriz(int *matriz, int linhas, int cols);

int main() {
  int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  int result;

  result = soma_matriz(&matriz[0][0], 3, 3);

  printf("A soma da matriz eh %d\n", result);

  return 0;
}

int soma_matriz(int *matriz, int linhas, int cols) {
  int sum = 0;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < cols; j++) {
      sum += *(matriz + (i * linhas) + j);
    }
  }

  return sum;
}
