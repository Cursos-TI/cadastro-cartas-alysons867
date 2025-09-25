#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;

    float densidadePopulacional;
    float pibPerCapita;
};

void cadastrarCarta(struct Carta *carta) {
    printf("Digite a letra do Estado (A a H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void calcularDensidadePopulacional(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
}

void calcularPibPerCapita(struct Carta *carta) {
    // Converte PIB para reais (pib * 1.000.000.000)
    // e divide pela população
    carta->pibPerCapita = (carta->pib * 1000000000.0) / carta->populacao;
}

void exibirCarta(struct Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);
    calcularDensidadePopulacional(&carta1);
    calcularPibPerCapita(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);
    calcularDensidadePopulacional(&carta2);
    calcularPibPerCapita(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
// Programa para cadastrar e exibir cartas de cidades brasileiras com atributos específicos.
