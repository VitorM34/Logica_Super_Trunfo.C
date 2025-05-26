#include <stdio.h>
#include <string.h>

// estrutura que guarda os dados de uma cidade
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
} Cidade;

int main() {
    Cidade c1, c2; // duas cidades para comparar
    char atributo[20]; // nome do atributo que o usuário vai digitar

    // pega os dados da primeira cidade
    printf("Dados da primeira cidade:\n");
    printf("Nome: ");
    fgets(c1.nome, 50, stdin);
    c1.nome[strcspn(c1.nome, "\n")] = 0; // remove o enter

    printf("Populacao: ");
    scanf("%d", &c1.populacao);

    printf("Area: ");
    scanf("%f", &c1.area);

    printf("PIB: ");
    scanf("%f", &c1.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &c1.pontos);

    while (getchar() != '\n'); // limpa o buffer do teclado

    // calcula densidade (populacao dividido pela área)
    c1.densidade = (c1.area != 0) ? c1.populacao / c1.area : 0;

    // agora pega os dados da segunda cidade
    printf("\nDados da segunda cidade:\n");
    printf("Nome: ");
    fgets(c2.nome, 50, stdin);
    c2.nome[strcspn(c2.nome, "\n")] = 0;

    printf("Populacao: ");
    scanf("%d", &c2.populacao);

    printf("Area: ");
    scanf("%f", &c2.area);

    printf("PIB: ");
    scanf("%f", &c2.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &c2.pontos);

    while (getchar() != '\n');

    c2.densidade = (c2.area != 0) ? c2.populacao / c2.area : 0;

    // pergunta o que o usuário quer comparar
    printf("\nComparar por qual atributo? ");
    fgets(atributo, 20, stdin);
    atributo[strcspn(atributo, "\n")] = 0;

    // agora faz a comparação de acordo com o atributo escolhido
    printf("\nResultado: ");
    if (strcmp(atributo, "populacao") == 0) {
        if (c1.populacao > c2.populacao)
            printf("%s ganhou\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("%s ganhou\n", c2.nome);
        else
            printf("Empate\n");

    } else if (strcmp(atributo, "area") == 0) {
        if (c1.area > c2.area)
            printf("%s ganhou\n", c1.nome);
        else if (c2.area > c1.area)
            printf("%s ganhou\n", c2.nome);
        else
            printf("Empate\n");

    } else if (strcmp(atributo, "pib") == 0) {
        if (c1.pib > c2.pib)
            printf("%s ganhou\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("%s ganhou\n", c2.nome);
        else
            printf("Empate\n");

    } else if (strcmp(atributo, "pontos") == 0) {
        if (c1.pontos > c2.pontos)
            printf("%s ganhou\n", c1.nome);
        else if (c2.pontos > c1.pontos)
            printf("%s ganhou\n", c2.nome);
        else
            printf("Empate\n");

    } else if (strcmp(atributo, "densidade") == 0) {
        // nesse caso, ganha a que tiver menor densidade
        if (c1.densidade < c2.densidade)
            printf("%s ganhou (menor densidade)\n", c1.nome);
        else if (c2.densidade < c1.densidade)
            printf("%s ganhou (menor densidade)\n", c2.nome);
        else
            printf("Empate\n");
    } else {
        // se digitou um nome errado
        printf("Atributo invalido\n");
    }

    return 0;
}

/*
    Esse programa compara duas cidades com base em um atributo digitado pelo usuário.
    Ele pede nome, população, área, PIB e pontos turísticos de cada cidade, calcula a densidade populacional
    (população / área) e depois compara o atributo escolhido.

    Como compilar:

    No Linux/macOS:
        gcc nome_do_arquivo.c -o cidades
        ./cidades

    No Windows:
        gcc nome_do_arquivo.c -o cidades.exe
        cidades.exe

    Obs: troque "nome_do_arquivo.c" pelo nome real do seu arquivo.
*/