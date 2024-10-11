#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
    char cargo[20];
} Funcionario;


int main() {
    Funcionario func[3];

    for (int i = 0; i < 3; ++i) {
        printf("Digite o nome do funcionario: ");
        fgets(func[i].nome, sizeof(func[i].nome), stdin);

        printf("Digite a idade do funcionario: ");
        scanf("%d", &func[i].idade);

        printf("Digite o salario do funcionario: ");
        scanf("%f", &func[i].salario);
        getchar();

        printf("Digite o cargo do funcionario: ");
        fgets(func[i].cargo, sizeof(func[i].cargo), stdin);
        printf("\n");
    }

    printf("Funcionarios: \n");
    for (int i = 0; i < 3; ++i) {
        printf("Funcionario %d:\n", i + 1);

        printf("Nome: %s", func[i].nome);
        printf("Idade: %d\n", func[i].idade);
        printf("Salario: %.2f\n", func[i].salario);
        printf("Cargo: %s", func[i].cargo);
        printf("\n");
    }
}
