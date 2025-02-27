#include <stdio.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib +
                         carta->pontos_turisticos + carta->pib_per_capita + (1 / carta->densidade_populacional);
}

// Função para ler os dados de uma carta
void ler_carta(Carta *carta) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Digite o codigo: ");
    scanf(" %s", carta->codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", carta->nome);
    printf("Digite a populacao: ");
    scanf(" %lu", &carta->populacao);
    printf("Digite a area: ");
    scanf(" %f", &carta->area);
    printf("Digite o PIB: ");
    scanf(" %f", &carta->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf(" %d", &carta->pontos_turisticos);
    
    calcular_atributos(carta);
}

// Função para comparar os atributos das cartas e exibir os vencedores
void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparacao de Cartas:\n");
    printf("Populacao: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    printf("Area: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2, c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional ? 1 : 2, c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita ? 1 : 2, c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", c1.super_poder > c2.super_poder ? 1 : 2, c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;
    
    printf("Cadastro da Carta 1:\n");
    ler_carta(&carta1);
    
    printf("\nCadastro da Carta 2:\n");
    ler_carta(&carta2);
    
    comparar_cartas(carta1, carta2);
    
    return 0;
}