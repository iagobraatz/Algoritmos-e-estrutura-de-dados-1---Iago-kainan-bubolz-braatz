#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s) {
    int esquerda = 0;
    int direita = strlen(s) - 1;

    while (esquerda < direita) {
        while (esquerda < direita && !isalnum(s[esquerda]))
            esquerda++;

        while (esquerda < direita && !isalnum(s[direita]))
            direita--;

        if (tolower(s[esquerda]) != tolower(s[direita]))
            return false;

        esquerda++;
        direita--;
    }

    return true;
}
