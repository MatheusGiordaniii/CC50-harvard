// Cria duas pirâmides usando "#"

#include <stdio.h>
#include <cs50.h>

// Protótipo
void hash(int numH, int num);

int main(void) {
    
    // Pega o valor da altura
    int height;
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 15);

    // chama a função hash e define quantas vezes o hash e o espaço serão repetidos
    int hsNum = 1;
    int scNum = height--;
    for (int j = 0; j <= height; j++) {
        hash(hsNum, scNum);
        hsNum++;
        scNum--;
    }
}

void hash(int numH, int numS) {
    
    // Repete o espaço numS vezes
    for(int k = 0; k < numS; k++) {
            printf(" ");
    }
    // Repete o hash numH vezes
    for (int i = 0; i < numH; i++) {
        printf("#");
    }
    // Repete o hash numH vezes e se for a primeira vez adiciona espaço
    for (int i = 0; i < numH; i++) {
        if (i == 0){
            printf("  ");
        }
        printf("#");
    }
    printf("\n");
}
