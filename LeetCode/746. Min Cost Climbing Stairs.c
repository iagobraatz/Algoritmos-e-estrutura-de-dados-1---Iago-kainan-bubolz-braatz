int minCostClimbingStairs(int* cost, int costSize) {
    int anterior = 0;
    int atual = 0;
    int proximo;

    for (int i = 2; i <= costSize; i++) {
        int custo1 = atual + cost[i - 1];
        int custo2 = anterior + cost[i - 2];
        proximo = custo1 < custo2 ? custo1 : custo2;
        anterior = atual;
        atual = proximo;
    }

    return atual;
}
