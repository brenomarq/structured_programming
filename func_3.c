#include <stdio.h>

float media(float num[3]) {
    float sum;
    for (int i = 0; i < 3; ++i) sum += num[i];

    return sum / 3;
}

int main() {
    float num[3];

    printf("Digite tres notas:\n");
    for (int i = 0; i < 3; ++i) {
        scanf("%f", &num[i]);
    }

    printf("A media aritmetica dos numeros eh %.2f\n", media(num));

    return 0;
}
