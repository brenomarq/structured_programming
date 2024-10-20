#include <stdio.h>

int square(int n) {
    return n * n;
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("O quadrado de %d eh %d\n", num, square(num));

    return 0;
}
