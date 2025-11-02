//iago kainan bubolz braatz - m2 - AED1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int contador = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            bool vazioEsquerda = (i == 0) || (flowerbed[i - 1] == 0);
            bool vazioDireita = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);

            if (vazioEsquerda && vazioDireita) {
                flowerbed[i] = 1;
                contador++;
            }
        }
    }

    return contador >= n;
}

int main() {
    int flowerbedSize, n;

    printf("digite o tamanho do canteiro: ");
    scanf("%d", &flowerbedSize);

    int flowerbed[flowerbedSize];

    printf("digite os valores do canteiro (0 para vazio, 1 para ocupado):\n");
    for (int i = 0; i < flowerbedSize; i++) {
        scanf("%d", &flowerbed[i]);
    }

    printf("digite quantas flores quer plantar: ");
    scanf("%d", &n);

    if ( canPlaceFlowers(flowerbed, flowerbedSize, n )){
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
