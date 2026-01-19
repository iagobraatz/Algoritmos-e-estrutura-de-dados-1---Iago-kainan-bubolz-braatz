#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    int* resultado = malloc((digitsSize + 1) * sizeof(int));
    resultado[0] = 1;
    for (int i = 1; i <= digitsSize; i++)
        resultado[i] = 0;

    *returnSize = digitsSize + 1;
    return resultado;
}
