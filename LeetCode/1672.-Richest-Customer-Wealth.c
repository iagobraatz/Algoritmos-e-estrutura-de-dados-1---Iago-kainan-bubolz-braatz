#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maxWealth = 0;
    
    for (int i = 0; i < accountsSize; i++) {
        int sum = 0;
        for (int j = 0; j < accountsColSize[i]; j++) {
            sum += accounts[i][j];
        }
        if (sum > maxWealth) {
            maxWealth = sum;
        }
    }
    
    return maxWealth;
}

int main() {
    int m, n;
    
    printf("Digite o numero de clientes: ");
    scanf("%d", &m);
    printf("Digite o numero de bancos por cliente: ");
    scanf("%d", &n);

    
    int** accounts = (int**) malloc(m * sizeof(int*));
    int* accountsColSize = (int*) malloc(m * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        accounts[i] = (int*) malloc(n * sizeof(int));
        accountsColSize[i] = n;
        printf("Digite os saldos do cliente %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &accounts[i][j]);
        }
    }

    int result = maximumWealth(accounts, m, accountsColSize);
    printf("A maior riqueza de um cliente e: %d\n", result);

    for (int i = 0; i < m; i++) {
        free(accounts[i]);
    }
    free(accounts);
    free(accountsColSize);

    return 0;
}
