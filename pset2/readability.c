// Calcula o nível de grade necessário para compreender algum texto

#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    string text = get_string("Text: ");

    // Contador de letras
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }

    // Contador de palavras
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isspace(text[i])) {
            words++;
        }
    }

    // Contador de sentenças
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    // Calcula o índice Coleman-Liau
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Define um valor mínimo e um máximo
    if (index <= 0) {
        index = 1;
    } else if (index >= 16) {
        index = 16;
    }

    printf("Letters: %i Words: %i Sentences: %i\n", letters, words, sentences);
    printf("Grade: %i\n", (int)index);
}