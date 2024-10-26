#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
  char nome[MAX]; // Nome pode ter 50 caracteres
  char telefone[MAX - 35]; // Telefone pode ter 15 caracteres
  char email[MAX]; // email pode ter 50 caracteres
} Contato;

/*Essa função adiciona um contato na posição especificada da lista e retorna 1
em caso de sucesso, 0 em caso de falha.*/
int adicionar_contato(Contato contatos[], int pos_atual);

int main() {
  Contato contatos[MAX];
  int entrada, result, pos_atual = 0;

  do {
    printf("LISTA DE CONTATOS\n");
    printf("Gerenciamos seus contatos com eficiência.\n");
    printf("------------------------------------------\n");
    printf("\nDigite uma das opções abaixo:\n");
    printf("[1] adicionar [2] remover [3] buscar [4] listar todos: ");
    scanf("%d", &entrada);
    getchar();

    switch (entrada) {
      case 1: // Incluir lógica de adição de contato
        result = adicionar_contato(contatos, pos_atual);

        if (result) {
          pos_atual++; // Avança para uma posição vazia na lista
          printf("\nContato adicionado com sucesso!\n");
        }

        break;

      case 2: // Incluir lógica de remoção de contato
        break;

      case 3: // Incluir lógica de busca
        break;

      case 4: // Incluir lógica para listar todos os contatos
        break;

      default:
        printf("\nOpção inválida!\n");
        break;
    }

    printf("\nVocê deseja continuar o programa?\n");
    printf("Digite [0], caso deseje finalizar: ");
    scanf("%d", &entrada);
    system("clear");
  } while (entrada != 0);

  printf("PROGRAMA FINALIZADO!\n");

  return 0;
}

int adicionar_contato(Contato contatos[], int pos_atual) {
  int successful = 0;

  system("clear");
  printf("Adicionar Contato:\n");
  printf("--------------------\n");
  printf("Digite o nome: ");
  fgets(contatos[pos_atual].nome, sizeof(contatos[pos_atual].nome), stdin);
  printf("Digite o telefone: ");
  fgets(contatos[pos_atual].telefone, sizeof(contatos[pos_atual].telefone), stdin);
  printf("Digite o email: ");
  fgets(contatos[pos_atual].email, sizeof(contatos[pos_atual].email), stdin);

  successful = 1; // Confirma que a operação foi bem sucedida
  return successful;
}
