#include <stdio.h>
typedef struct {
    char titulo[50];
    char autor[50];
    int ano;
    char isbn[50];
} Livro;

int main() {
    Livro livros[5];

    for (int i = 0; i < 5; ++i) {
        printf("Digite os dados do livro: \n");
        printf("Titulo: ");
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);

        printf("Autor: ");
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);

        printf("ISBN: ");
        fgets(livros[i].isbn, sizeof(livros[i].isbn), stdin);

        printf("Ano de publicacao: ");
        scanf("%d", &livros[i].ano);

        getchar();
        printf("\n");
    }

    printf("\nImprimindo livros:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Livro %d:\n", i + 1);
        printf("Titulo: %s", livros[i].titulo);
        printf("Autor: %s", livros[i].autor);
        printf("Ano: %d\n", livros[i].ano);
        printf("ISBN: %s\n", livros[i].isbn);
    }
}
