#include <stdio.h>

#define MAX 100

int sum(int num[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += num[i];
    }

    return sum;
}

int main() {
    int n, num[MAX];

    printf("Digite quantos numeros voce deseja somar: ");
    scanf("%d", &n);

    if (n > MAX || n < 1) {
        printf("Digite um numero de 0 a 100.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("A soma dos numeros eh %d.\n", sum(num, n));
    return 0;
}
