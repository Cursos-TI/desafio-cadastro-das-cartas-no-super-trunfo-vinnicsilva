#include <stdio.h>

// Cálculo dos dados para Densidade Populacional e PIB per Capita
void calcular_dados(unsigned long int populacao, float area, float pib, float *densidade, float *pib_per_capita) {
    *densidade = populacao / area;
    *pib_per_capita = (pib * 1000000000.0f) / populacao;
}

// Função para o Super Poder da carta
float superPoder(unsigned long int populacao, float area, float pib, int pontos_turisticos, float densidade, float pib_per_capita) {
    float inverso_densidade = 1 / densidade;
    return populacao + area + pib + pontos_turisticos + pib_per_capita + inverso_densidade;
}

// Função para comparar os valores das duas cartas 
void comparar(unsigned long int populacao1, unsigned long int populacao2,
              float area1, float area2,
              float pib1, float pib2,
              int pontos_turisticos1, int pontos_turisticos2,
              float densidade1, float densidade2,
              float super1, float super2, char *cidade1, char *cidade2, float pib_per_capita1, float pib_per_capita2) {

    // Comparação de Super Poder
    printf("\n=== Comparação de Cartas ===\n");

    if (populacao1 > populacao2) {
        printf("População: Carta 1 venceu (%s)\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("População: Carta 2 venceu (%s)\n", cidade2);
    };

    if (area1 > area2) {
        printf("Área: Carta 1 venceu (%s)\n", cidade1);
    } else if (area2 > area1) {
        printf("Área: Carta 2 venceu (%s)\n", cidade2);
    };

    if (pib1 > pib2) {
        printf("PIB: Carta 1 venceu (%s)\n", cidade1);
    } else if (pib2 > pib1) {
        printf("PIB: Carta 2 venceu (%s)\n", cidade2);
    };

    if (pontos_turisticos1 > pontos_turisticos2) {
        printf("Pontos Turísticos: Carta 1 venceu (%s)\n", cidade1);
    } else if (pontos_turisticos2 > pontos_turisticos1) {
        printf("Pontos Turísticos: Carta 2 venceu (%s)\n", cidade2);
    };

    if (densidade1 < densidade2) {
        printf("Densidade: Carta 2 venceu (%s)\n", cidade1);
    } else if (densidade2 < densidade1) {
        printf("Densidade: Carta 1 venceu (%s)\n", cidade2);
    };

    if (pib_per_capita1 > pib_per_capita2) {
        printf("PIB per Capita: Carta 1 venceu (%s)\n", cidade1);
    } else if (pib_per_capita2 > pib_per_capita1) {
        printf("PIB per Capita: Carta 2 venceu (%s)\n", cidade2);
    };

    if (super1 > super2) {
        printf("Super Poder: Carta 1 venceu (%s)\n", cidade1);
    } else if (super2 > super1) {
        printf("Super Poder: Carta 2 venceu (%s)\n", cidade2);
    } else {
        printf("Empate no Super Poder!\n");
    };
              
}

// função principal
int main() {
    // Declaração de variavéis
    char estado1[50], estado2[50];
    char codigo1[50], codigo2[50];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;
    float super1, super2;

    // Primeira carta
    printf("\n=== Cadastro da Primeira Carta ===\n");
    printf("Estado: "); fgets(estado1, 50, stdin);
    printf("Código da carta: "); scanf("%s", codigo1); getchar();
    printf("Cidade: "); fgets(cidade1, 50, stdin);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB (em bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos1);
    getchar();

    // Definição de dados da Carta 1 para Calculo de Dados e Super Poder 
    calcular_dados(populacao1, area1, pib1, &densidade1, &pib_per_capita1);
    super1 = superPoder(populacao1, area1, pib1, pontos_turisticos1, densidade1, pib_per_capita1);

    // Segunda carta
    printf("\n=== Cadastro da Segunda Carta ===\n");
    printf("Estado: "); fgets(estado2, 50, stdin);
    printf("Código da carta: "); scanf("%s", codigo2); getchar();
    printf("Cidade: "); fgets(cidade2, 50, stdin);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB (em bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos2);
    getchar();

    // Definição de dados da Carta 2 para Calculo de Dados e Super Poder 
    calcular_dados(populacao2, area2, pib2, &densidade2, &pib_per_capita2);
    super2 = superPoder(populacao2, area2, pib2, pontos_turisticos2, densidade2, pib_per_capita2);

    // Parte na qual é comparado os dados das cartas 1 e 2 para decidir a vencedora
    comparar(populacao1, populacao2, area1, area2, pib1, pib2,
             pontos_turisticos1, pontos_turisticos2, densidade1, densidade2,
             super1, super2, cidade1, cidade2, pib_per_capita1, pib_per_capita2);

    return 0;
}
