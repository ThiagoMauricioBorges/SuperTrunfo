#include <stdio.h>

int main() {
    // Variáveis para armazenar os dados das cartas
    char estado1, estado2;
    char codigo1[5], codigo2[5];  // Para armazenar o código da carta (máximo 4 caracteres + '\0')
    char cidade1[50], cidade2[50]; // Para armazenar os nomes das cidades (máximo 50 caracteres + '\0')
    unsigned long int populacao1, populacao2; // Alterado para unsigned long int
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // Leitura dos dados da primeira carta
    printf("Informe os dados da primeira carta:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1);  // O espaço antes de %c serve para limpar o buffer de entrada
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    getchar();  // Limpa o buffer de entrada
    fgets(cidade1, 50, stdin); // Lê o nome da cidade (permite espaços)
    cidade1[strcspn(cidade1, "\n")] = '\0';  // Remove a quebra de linha no final da string
    printf("População: ");
    scanf("%lu", &populacao1); // Alterado para %lu para ler unsigned long int
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // Leitura dos dados da segunda carta
    printf("\nInforme os dados da segunda carta:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);  // O espaço antes de %c serve para limpar o buffer de entrada
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    getchar();  // Limpa o buffer de entrada
    fgets(cidade2, 50, stdin); // Lê o nome da cidade (permite espaços)
    cidade2[strcspn(cidade2, "\n")] = '\0';  // Remove a quebra de linha no final da string
    printf("População: ");
    scanf("%lu", &populacao2); // Alterado para %lu para ler unsigned long int
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos da densidade populacional e PIB per capita
    densidade1 = populacao1 / area1;
    pibPerCapita1 = pib1 * 1e9 / populacao1;  // Convertendo PIB para reais

    densidade2 = populacao2 / area2;
    pibPerCapita2 = pib2 * 1e9 / populacao2;  // Convertendo PIB para reais

    // Cálculo do Super Poder
    superPoder1 = (float)populacao1 + area1 + pib1 * 1e9 + pontos1 + (1.0 / densidade1) + pibPerCapita1;
    superPoder2 = (float)populacao2 + area2 + pib2 * 1e9 + pontos2 + (1.0 / densidade2) + pibPerCapita2;

    // Exibindo os resultados das comparações
    printf("\nComparação de Cartas:\n");

    // Comparando População
    printf("População: ");
    if (populacao1 > populacao2)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparando Área
    printf("Área: ");
    if (area1 > area2)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparando PIB
    printf("PIB: ");
    if (pib1 > pib2)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparando Número de Pontos Turísticos
    printf("Pontos Turísticos: ");
    if (pontos1 > pontos2)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparando Densidade Populacional
    printf("Densidade Populacional: ");
    if (densidade1 < densidade2) // Menor densidade vence
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparando PIB per Capita
    printf("PIB per Capita: ");
    if (pibPerCapita1 > pibPerCapita2)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparando Super Poder
    printf("Super Poder: ");
    if (superPoder1 > superPoder2)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    return 0;
}
