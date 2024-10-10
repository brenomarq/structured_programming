#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Ponto;

int main() {
    Ponto ponto1, ponto2;
    float result;

    printf("Digite as coordenadas x e y do ponto 1:\n");
    printf("x: ");
    scanf("%f", &ponto1.x);
    printf("y: ");
    scanf("%f", &ponto1.y);

    printf("Digite as coordenadas x e y do ponto 2: ");
    printf("x: ");
    scanf("%f", &ponto2.x);
    printf("y: ");
    scanf("%f", &ponto2.y);

    result = sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2));

    printf("A distancia entre o ponto 1 e o ponto 2 eh %.2f\n", result);

    return 0;
}
