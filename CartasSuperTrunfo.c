#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARTAS 32


typedef struct {
    char estado;               // Letra do estado (A-H)
    char codigo[4];            // Código da carta (ex: A01)
    char cidade[50];           // Nome da cidade
    int populacao;             // População da cidade
    float area;                // Área da cidade em km²
    float pib;                 // PIB da cidade
    int pontos_turisticos;     // Número de pontos turísticos
} Carta;

void cadastrar_carta(Carta *carta) {
    printf("\nDigite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    carta->estado = toupper(carta->estado);

    if (carta->estado < 'A' || carta->estado > 'H') {
        printf("Estado inválido! Insira uma letra de A a H.\n");
        return;
    }

    printf("Digite o código da carta (%c01 a %c04): ", carta->estado, carta->estado);
    scanf("%s", carta->codigo);

    if (strlen(carta->codigo) != 3 || carta->codigo[0] != carta->estado || carta->codigo[1] < '0' || carta->codigo[1] > '4') {
        printf("Código inválido! Deve estar no formato %c01 a %c04.\n", carta->estado, carta->estado);
        return;
    }

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", carta->cidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta->pontos_turisticos);

    printf("\nCarta cadastrada com sucesso!\n");
}

void exibir_carta(const Carta *carta) {
    printf("\n--- Dados da Carta %s ---\n", carta->codigo);
    printf("Estado: %c\n", carta->estado);
    printf("Código da carta: %s\n", carta->codigo);
    printf("Nome da cidade: %s\n", carta->cidade);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: R$%.2f\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
}

int main() {
    Carta cartas[MAX_CARTAS];
    int total_cartas = 0;
    int opcao;

    do {
        printf("\n=== Super Trunfo: Cadastro de Cartas ===\n");
        printf("1. Cadastrar nova carta\n");
        printf("2. Exibir cartas cadastradas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total_cartas < MAX_CARTAS) {
                    cadastrar_carta(&cartas[total_cartas]);
                    total_cartas++;
                } else {
                    printf("\nLimite de cartas atingido!\n");
                }
                break;

            case 2:
                if (total_cartas == 0) {
                    printf("\nNenhuma carta cadastrada.\n");
                } else {
                    for (int i = 0; i < total_cartas; i++) {
                        exibir_carta(&cartas[i]);
                    }
                }
                break;

            case 3:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

