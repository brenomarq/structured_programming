#include <stdio.h>

int quantos_digitos(int n) {
    int quant = 0;

    do {
        ++quant;

        n /= 10;
    } while (n != 0);

    return quant;
}

int main() {
    int num;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Numero invalido.\n");
        return 1;
    }

    printf("O numero %d tem %d digitos.\n", num, quantos_digitos(num));

    return 0;
}
