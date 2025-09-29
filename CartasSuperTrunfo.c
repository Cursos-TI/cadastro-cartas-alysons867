#include <stdio.h>
#include <string.h>

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
    float superPoder;
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

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

void calcularDensidadePopulacional(struct Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0.0;
}

void calcularPibPerCapita(struct Carta *carta) {
    if (carta->populacao > 0)
        carta->pibPerCapita = (carta->pib * 1000000000.0) / carta->populacao;
    else
        carta->pibPerCapita = 0.0;
}

void calcularSuperPoder(struct Carta *carta) {
    float inversoDensidade = (carta->densidadePopulacional > 0) ? (1.0 / carta->densidadePopulacional) : 0.0;

    carta->superPoder = 
        (float)carta->populacao +
        carta->area +
        carta->pib +  // PIB já está em bilhões
        (float)carta->pontosTuristicos +
        carta->pibPerCapita +
        inversoDensidade;
}

void exibirCarta(struct Carta carta, int numero) {
    printf("\n-----------------------------\n");
    printf("Carta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void compararCartas(struct Carta c1, struct Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);
    calcularDensidadePopulacional(&carta1);
    calcularPibPerCapita(&carta1);
    calcularSuperPoder(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);
    calcularDensidadePopulacional(&carta2);
    calcularPibPerCapita(&carta2);
    calcularSuperPoder(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}
