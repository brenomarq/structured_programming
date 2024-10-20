#include <stdio.h>

float to_fahrenheit(float celsius) {
    float temp = (9.0 / 5.0) * celsius + 32;

    return temp;
}

float to_celsius(float fahrenheit) {
    float temp = (fahrenheit - 32) * (5.0 / 9.0);

    return temp;
}

int main() {
    int choice;
    float temp;

    printf("CONVERSOR DE TEMPERATURA\n");
    printf("\nDigite [1] para converter celsius para fahrenheit\n");
    printf("Digite [2] para converter fahrenheit para celsius\n");
    printf("Escolha: ");
    scanf("%d", &choice);
    printf("Digite a temperatura: ");
    scanf("%f", &temp);

    switch (choice) {
        case 1:
            printf("A temperatura em fahrenheit eh %.2f.\n", to_fahrenheit(temp));
            break;

        case 2:
            printf("A temperatura em celsius eh %.2f.\n", to_celsius(temp));
            break;

        default:
            printf("Escolha invalida.\n");
    }

    return 0;
}
