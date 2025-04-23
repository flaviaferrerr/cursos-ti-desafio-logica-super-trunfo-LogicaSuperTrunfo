criei o printf
#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função que calcula Densidade Populacional e PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para imprimir os dados principais da carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f Bilhoes\n", carta.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("--------------------------------------\n");
}

// Função que compara as duas cartas com base em Densidade Populacional
void compararCartasPorDensidade(Carta c1, Carta c2) {
    printf("\nComparacao de cartas (Atributo: Densidade Populacional):\n\n");
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", c1.nomeCidade, c1.estado, c1.densidadePopulacional);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", c2.nomeCidade, c2.estado, c2.densidadePopulacional);

    if (c1.densidadePopulacional < c2.densidadePopulacional) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.densidadePopulacional < c1.densidadePopulacional) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Cadastro das cartas (dados fixos neste nível)
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6748000, 1182.30, 407.10, 30};

    // Calcula os indicadores para cada carta
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibe as cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);
    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Comparar cartas com base em Densidade Populacional
    compararCartasPorDensidade(carta1, carta2);

    return 0;
}
