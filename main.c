/*
  Desafio de Struct
  Criar um programa que receba contatos do usuário e realize as funções de
adicionar, remover, buscar e listar todos os contatos adicionados.
*/
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
  Contato* primeiro;
} Lista;

/*Essa função é responsável por criar uma nova entidade de contato com um ID
único e retorna um ponteiro para essa entidade.*/
Contato *criar_contato(int* pos_atual);

/*Essa função adiciona um novo contato na última posição livre da lista
de contatos.*/
void adicionar_contato(Contato* contato, Lista* Lista);

/*Essa função remove o contato da lista de contatos por meio do ID único.
Ela retorna 1 em caso de sucesso, e 0 em caso de falha na busca.*/
int remover_contato(int id, Lista* lista);

/*Essa função busca um contato pelo ID especificado e retorna
um ponteiro para aquele contato.*/
Contato *buscar_contato(int id, Lista* lista);

/*Essa função lista e imprime todos os contatos adicionados.*/
void listar_contatos(Lista* lista);

/*Essa função imprime o contato especificado de maneira formatada e agradável
ao usuário do sistema.*/
void imprimir_contato(Contato* contato);

/*Essa função limpa o espaço ocupado por todos os contatos criados.*/
void limpar_contatos(Lista* lista);

int main() {
  int entrada, pos_atual = 1;
  Lista* contatos = (Lista*) malloc(sizeof(Lista)); // Cria lista de contatos
  contatos->primeiro = NULL; // A lista começa vazia sem nenhum contato
  Contato* contato_temp; // Armazena cada novo contato temporariamente

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
        contato_temp = criar_contato(&pos_atual);
        adicionar_contato(contato_temp, contatos);

        printf("\nContato adicionado com sucesso!\n");
        break;

      case 2: // Opção de remover elemento
        system("clear");
        printf("Digite o ID do contato a ser removido: ");
        scanf("%d", &entrada);
        getchar();

        if (remover_contato(entrada, contatos)) {
          printf("\nContato de ID [%d] removido com sucesso!\n", entrada);
        } else {
          printf("\nContato não encontrado na lista!\n");
        }
        break;

      case 3: // Opção de buscar elementos
        system("clear");
        printf("Digite o ID do contato: ");
        scanf("%d", &entrada);
        getchar();

        contato_temp = buscar_contato(entrada, contatos);
        if (contato_temp == NULL) {
          printf("\nO contato não foi encontrado!\n");
        } else {
          imprimir_contato(contato_temp);
        }
        break;

      case 4: // Opção para listar todos os contatos
        system("clear");
        printf("MEUS CONTATOS\n");
        printf("--------------\n");
        listar_contatos(contatos);
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

Contato *criar_contato(int* pos_atual) {
  Contato* novo_contato = (Contato*) malloc(sizeof(Contato));
  novo_contato->proximo = NULL; // Atribui um valor nulo ao próximo contato
  novo_contato->id = *pos_atual; // Atribui um ID único a cada contato

  system("clear");
  printf("Adicionar Contato\n");
  printf("--------------------\n");
  printf("Digite o nome: ");
  fgets(novo_contato->nome, sizeof(novo_contato->nome), stdin);
  printf("Digite o telefone: ");
  fgets(novo_contato->telefone, sizeof(novo_contato->telefone), stdin);
  printf("Digite o email: ");
  fgets(novo_contato->email, sizeof(novo_contato->email), stdin);

  (*pos_atual)++; // Modifica a variável para identificar outros contatos
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

int remover_contato(int id, Lista* lista) {
  Contato* anterior, *temp; // Definem-se variáveis temporárias de armazenamento
  Contato* atual = lista->primeiro; // Define o atual como o primeiro da lista

  if (atual->id == id) {
    // Executa se o ID corresponde ao primeiro elemento da lista
    temp = atual->proximo;
    free(atual);
    lista->primeiro = temp;

    return 1; // Operação realizada com sucesso
  }

  while (atual != NULL) {
    if (atual->id == id) {
      temp = atual->proximo; // Armazena o próximo elemento associado
      free(atual); // Remove o elemento selecionado
      anterior->proximo = temp; // Associa o próximo do elemento removido

      return 1; // Elemento encontrado e removido
    }

    anterior = atual;
    atual = atual->proximo; // Passa para o próximo contato
  }

  return 0; // O elemento não foi encontrado
}

Contato *buscar_contato(int id, Lista* lista) {
  Contato* atual = lista->primeiro;

  while (atual != NULL) {
    if (atual->id == id) {
      return atual; // Contato encontrado e retornado com sucesso
    }

    atual = atual->proximo; // Visita o próximo contato
  }

  return atual; // Contato não encontrado, logo retorna NULL
}

void listar_contatos(Lista* lista) {
  Contato* atual = lista->primeiro;

  if (atual == NULL) {
    printf("\nA lista está vazia sem contatos!\n");
    return;
  }

  while (atual != NULL) {
    imprimir_contato(atual);
    atual = atual->proximo;
  }
}

void imprimir_contato(Contato* contato) {
  printf("Contato de ID [%d]\n", contato->id);
  printf("--------------------\n");
  printf("Nome: %s", contato->nome);
  printf("Telefone: %s", contato->telefone);
  printf("Email: %s\n", contato->email);
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
