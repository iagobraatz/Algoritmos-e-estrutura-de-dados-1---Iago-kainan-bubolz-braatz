

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int size;
    int maxSize;
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = malloc(sizeof(CustomStack));
    obj->stack = malloc(sizeof(int) * maxSize);
    obj->size = 0;
    obj->maxSize = maxSize;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->size < obj->maxSize) {
        obj->stack[obj->size] = x;
        obj->size++;
    }
}

int customStackPop(CustomStack* obj) {
    if (obj->size == 0) return -1;
    obj->size--;
    return obj->stack[obj->size];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if (k > obj->size) k = obj->size;
    for (int i = 0; i < k; i++)
        obj->stack[i] += val;
}

void customStackFree(CustomStack* obj) {
    free(obj->stack);
    free(obj);
}
