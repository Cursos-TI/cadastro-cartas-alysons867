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

// Função que compara duas cartas com base em um único atributo
void compararPorPopulacao(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%c): %lu habitantes\n", c1.nomeCidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%c): %lu habitantes\n", c2.nomeCidade, c2.estado, c2.populacao);

    // Compara populações
    if (c1.populacao > c2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.populacao > c1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("\nResultado: Empate! Ambas têm a mesma população.\n");
    }
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

    // Comparar por um único atributo (População, neste exemplo)
    compararPorPopulacao(carta1, carta2);

    return 0;
}
