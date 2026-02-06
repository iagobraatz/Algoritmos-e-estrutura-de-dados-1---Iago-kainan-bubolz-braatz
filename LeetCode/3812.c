/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct No {
    int vizinho;
    int indice_aresta;
    struct No* prox;
} No;

int* minimumFlips(int n, int** edges, int edgesSize, int* edgesColSize, char* start, char* target, int* returnSize) {
    No** lista = (No**)calloc(n, sizeof(No*));
    
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        
        No* novo1 = (No*)malloc(sizeof(No));
        novo1->vizinho = b;
        novo1->indice_aresta = i;
        novo1->prox = lista[a];
        lista[a] = novo1;
        
        No* novo2 = (No*)malloc(sizeof(No));
        novo2->vizinho = a;
        novo2->indice_aresta = i;
        novo2->prox = lista[b];
        lista[b] = novo2;
    }
    
    int* grau = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        grau[edges[i][0]]++;
        grau[edges[i][1]]++;
    }
    
    int* diferenca = (int*)malloc(n * sizeof(int));
    int soma = 0;
    for (int i = 0; i < n; i++) {
        diferenca[i] = (start[i] - '0') ^ (target[i] - '0');
        soma ^= diferenca[i];
    }
    
    if (soma != 0) {
        int* resultado = (int*)malloc(sizeof(int));
        resultado[0] = -1;
        *returnSize = 1;
        return resultado;
    }
    
    int* fila = (int*)malloc(n * sizeof(int));
    int inicio = 0, fim = 0;
    
    for (int i = 0; i < n; i++) {
        if (grau[i] == 1)
            fila[fim++] = i;
    }
    
    int* visitado = (int*)calloc(n, sizeof(int));
    int* usado = (int*)calloc(edgesSize, sizeof(int));
    
    while (inicio < fim) {
        int no = fila[inicio++];
        visitado[no] = 1;
        
        for (No* atual = lista[no]; atual != NULL; atual = atual->prox) {
            int viz = atual->vizinho;
            int ind = atual->indice_aresta;
            
            if (visitado[viz])
                continue;
            
            if (diferenca[no] == 1) {
                usado[ind] = 1;
                diferenca[viz] ^= 1;
            }
            
            grau[viz]--;
            if (grau[viz] == 1)
                fila[fim++] = viz;
        }
    }
    
    int* resposta = (int*)malloc(edgesSize * sizeof(int));
    int tamanho = 0;
    
    for (int i = 0; i < edgesSize; i++) {
        if (usado[i])
            resposta[tamanho++] = i;
    }
    
    *returnSize = tamanho;
    return resposta;
}
