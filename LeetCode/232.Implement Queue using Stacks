#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100;
    queue->stack1 = (int*)malloc(queue->capacity * sizeof(int));
    queue->stack2 = (int*)malloc(queue->capacity * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
int main() {
    MyQueue* queue = myQueueCreate();
    
    printf("Initial empty: %s\n", myQueueEmpty(queue) ? "true" : "false");
    
    myQueuePush(queue, 1);
    printf("After push(1), empty: %s\n", myQueueEmpty(queue) ? "true" : "false");
    
    myQueuePush(queue, 2);
    printf("After push(2), peek: %d\n", myQueuePeek(queue));
    
    myQueuePush(queue, 3);
    printf("After push(3), pop: %d\n", myQueuePop(queue));
    printf("After pop, peek: %d\n", myQueuePeek(queue));
    
    printf("Pop: %d\n", myQueuePop(queue));
    printf("Pop: %d\n", myQueuePop(queue));
    printf("Final empty: %s\n", myQueueEmpty(queue) ? "true" : "false");
    
    myQueueFree(queue);
    return 0;
}
