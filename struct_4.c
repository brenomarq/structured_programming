#include <stdio.h>

typedef struct {
    float largura;
    float altura;
} Retangulo;


int main() {
    Retangulo ret;
    float area, perimetro;

    printf("Digite a largura do retangulo: ");
    scanf("%f", &ret.largura);

    printf("Digite a altura do retangulo: ");
    scanf("%f", &ret.altura);

    area = ret.largura * ret.altura;
    perimetro = 2 * ret.largura + 2 * ret.altura;

    printf("\nO perimetro do retangulo eh %.2f\n", perimetro);
    printf("A area do retangulo eh %.2f\n", area);
}
