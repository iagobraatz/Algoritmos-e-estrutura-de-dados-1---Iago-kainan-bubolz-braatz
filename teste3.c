#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros;
    int i;

    numeros = (int *)malloc(5 * sizeof(int));
    if (numeros == NULL) return 1;

    for (i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    free(numeros);

    return 0;
}
