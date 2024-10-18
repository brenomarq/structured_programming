#include <stdio.h>

int eh_par(int n) {
    if (n % 2 == 0) return 1;

    return 0;
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (eh_par(num)) {
        printf("O numero %d eh par.\n", num);
    } else {
        printf("O numero %d eh impar.\n", num);
    }

    return 0;
}
