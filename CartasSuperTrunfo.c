#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;

    float densidadePopulacional;
    float pibPerCapita;
};

// Limpa o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Lê os dados da carta com scanf/fgets
void cadastrarCarta(struct Carta *carta) {
    printf("Digite a letra do Estado (A a H): ");
    scanf(" %c", &carta->estado);
    limparBuffer();

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    limparBuffer();

    printf("Digite o nome da cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // remove \n

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Calcula densidade = população / área
void calcularDensidadePopulacional(struct Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0.0;
}

// Calcula PIB per capita = (PIB * 1 bilhão) / população
void calcularPibPerCapita(struct Carta *carta) {
    if (carta->populacao > 0)
        carta->pibPerCapita = (carta->pib * 1000000000.0) / carta->populacao;
    else
        carta->pibPerCapita = 0.0;
}

// Exibe os dados de uma carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    // Cadastro das cartas
    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);
    calcularDensidadePopulacional(&carta1);
    calcularPibPerCapita(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);
    calcularDensidadePopulacional(&carta2);
    calcularPibPerCapita(&carta2);

    // Exibição dos dados
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu de comparação
    int opcao;
    printf("\n=== Menu de Comparação de Cartas ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparar (1 a 5): ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("\nComparando por POPULAÇÃO:\n");
            printf("Carta 1 - %s: %lu habitantes\n", carta1.nomeCidade, carta1.populacao);
            printf("Carta 2 - %s: %lu habitantes\n", carta2.nomeCidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("\nComparando por ÁREA:\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.nomeCidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("\nComparando por PIB:\n");
            printf("Carta 1 - %s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
            printf("Carta 2 - %s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("\nComparando por PONTOS TURÍSTICOS:\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", carta1.nomeCidade, carta1.pontosTuristicos);
            printf("Carta 2 - %s: %d pontos turísticos\n", carta2.nomeCidade, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("\nComparando por DENSIDADE DEMOGRÁFICA:\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente com um número de 1 a 5.\n");
    }

    return 0;
}
