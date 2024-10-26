#include <stdio.h>
#include <stdlib.h>

typedef struct Contato Contato; // Definição parcial
struct Contato {
  int id; // Propriedade adicionada para auxiliar em algumas operações
  char nome[50];
  char telefone[15];
  char email[50];
  Contato* proximo;
};

typedef struct {
  Contato *primeiro;
} Lista;

/*Essa função é responsável por criar uma nova entidade de contato e retorna
um ponteiro como resultado.*/
Contato *criar_contato(void);

/*Essa função adiciona um novo contato na última posição livre da lista
de contatos.*/
void adicionar_contato(Contato* contato, Lista* Lista);

/*Essa função limpa o espaço ocupado por todos os contatos criados.*/
void limpar_contatos(Lista* lista);

int main() {
  int entrada;
  Lista* contatos = (Lista*) malloc(sizeof(Lista)); // Cria lista de contatos
  contatos->primeiro = NULL; // A lista começa vazia sem nenhum contato
  Contato* novo_contato; // Armazena cada novo contato temporariamente

  do {
    printf("LISTA DE CONTATOS\n");
    printf("Gerenciamos seus contatos com eficiência\n");
    printf("--------------------------------------------\n");
    printf("Digite uma das opções abaixo\n");
    printf("[1] adicionar [2] remover [3] buscar [4] listar todos: ");
    scanf("%d", &entrada);
    getchar(); // Evitar comportamentos indesejados no console

    switch (entrada) {
      case 1: // Opção de adicionar elemento
        novo_contato = criar_contato();
        adicionar_contato(novo_contato, contatos);

        printf("\nContato adicionado com sucesso!\n");
        break;

      case 2: // Opção de remover elemento
        break;

      case 3:
        break;

      case 4:
        break;

      default:
        printf("\nOpção inválida!\n");
        break;
    }

    printf("\nVocê deseja continuar o programa?\n");
    printf("Digite [0] para finalizar: ");
    scanf("%d", &entrada);
    system("clear");
  } while (entrada != 0);

  limpar_contatos(contatos);
  printf("PROGRAMA FINALIZADO!\n");
};

Contato *criar_contato() {
  Contato* novo_contato = (Contato*) malloc(sizeof(Contato));
  novo_contato->proximo = NULL;

  system("clear");
  printf("Adicionar Contato\n");
  printf("--------------------\n");
  printf("Digite o nome: ");
  fgets(novo_contato->nome, sizeof(novo_contato->nome), stdin);
  printf("Digite o telefone: ");
  fgets(novo_contato->telefone, sizeof(novo_contato->telefone), stdin);
  printf("Digite o email: ");
  fgets(novo_contato->email, sizeof(novo_contato->email), stdin);

  return novo_contato;
}

void adicionar_contato(Contato* contato, Lista* lista) {
  Contato* atual = lista->primeiro;

  // Se o primeiro elemento é nulo, adiciona ali
  if (lista->primeiro == NULL) {
    lista->primeiro = contato;
    return;
  }

  while (atual->proximo != NULL) {
    atual = atual->proximo; // Percorre os contatos até encontrar um espaço
  }

  atual->proximo = contato; // Conecta o último contato criado ao último adicionado
}

void limpar_contatos(Lista* lista) {
  Contato* atual = lista->primeiro;
  Contato* temp;

  if (atual == NULL) return; // Lista vazia não precisa limpar

  while (atual != NULL) {
    temp = atual->proximo; // Armazena temporariamente o próximo contato
    free(atual); // Limpa o contato
    atual = temp; // Visita o próximo elemento
  }

  free(lista); // Por fim limpa o espaço da lista;
}
