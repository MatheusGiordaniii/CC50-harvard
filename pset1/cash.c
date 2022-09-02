// Exibe o mínimo de moedas usadas para pagar uma dívida

#include <stdio.h>
#include <cs50.h>

int main(void) {
    // Pega o valor que está devendo
    float money = 0;
    do {
    money = get_float("Money owed: $");
    } while (money <= 0);

    // Checa qual é o mínimo de moedas a serem usadas
    int c25 = 0, c10 = 0, c5 = 0, c1 = 0;
    while (money >= 0.25) {
        money -= 0.25;
        c25++;
    }
    while (money >= 0.10) {
        money -= 0.10;
        c10++;
    }
    while (money >= 0.05) {
        money -= 0.05;
        c5++;
    }
    while (money >= 0.01) {
        money -= 0.01;
        c1++;
    }
    
    // Exibe quantas moedas de cada valor foram usadas
    int minC = c25 + c10+ c5 + c1;
    printf("Used coins: \n");
    printf("25 cents: %i\n", c25);
    printf("10 cents: %i\n", c10);
    printf("5  cents: %i\n", c5);
    printf("1  cent:  %i\n", c1);
    printf("Minimum possible coins:  %i\n coins", minC);
}