#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int main() {
    Data data;
    int eh_valida = 1;

    printf("Digite o dia: ");
    scanf("%d", &data.dia);

    printf("Digite o mes: ");
    scanf("%d", &data.mes);

    printf("Digite o ano: ");
    scanf("%d", &data.ano);

    if (data.ano < 0) eh_valida = 0;
    if (data.mes > 12 || data.mes < 1) eh_valida = 0;
    if (data.dia < 0) eh_valida = 0;


    switch (data.mes) {
        case 1:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;

        case 2:
            eh_valida = data.dia > 28 ? 0 : 1;
            break;

        case 3:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;

        case 4:
            eh_valida = data.dia > 30 ? 0 : 1;
            break;

        case 5:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;

        case 6:
            eh_valida = data.dia > 30 ? 0 : 1;
            break;

        case 7:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;

        case 8:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;

        case 9:
            eh_valida = data.dia > 30 ? 0 : 1;
            break;

        case 10:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;

        case 11:
            eh_valida = data.dia > 30 ? 0 : 1;
            break;

        case 12:
            eh_valida = data.dia > 31 ? 0 : 1;
            break;
    
        default:
            break;
    }

    if (eh_valida) {
        printf("A data %d/%d/%d eh valida\n", data.dia, data.mes, data.ano);
        return 0;
    }

    printf("A data %d/%d/%d nao eh valida\n", data.dia, data.mes, data.ano);
    return 0;
}
