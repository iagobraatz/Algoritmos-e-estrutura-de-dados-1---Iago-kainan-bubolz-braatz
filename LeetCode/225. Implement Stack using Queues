#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(Queue* queue, int x) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = x;
    queue->size++;
}

int dequeue(Queue* queue) {
    int x = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return x;
}

int peek(Queue* queue) {
    return queue->data[queue->front];
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q1, x);
}

int myStackPop(MyStack* obj) {
    while (obj->q1->size > 1) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int result = dequeue(obj->q1);
    
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    
    return result;
}

int myStackTop(MyStack* obj) {
    while (obj->q1->size > 1) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int result = peek(obj->q1);
    enqueue(obj->q2, dequeue(obj->q1));
    
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    
    return result;
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q1);
    freeQueue(obj->q2);
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate();
    
    printf("Stack created. Empty: %s\n", myStackEmpty(stack) ? "true" : "false");
    
    myStackPush(stack, 1);
    printf("Pushed 1. Empty: %s\n", myStackEmpty(stack) ? "true" : "false");
    
    myStackPush(stack, 2);
    printf("Pushed 2. Top: %d\n", myStackTop(stack));
    
    myStackPush(stack, 3);
    printf("Pushed 3. Top: %d\n", myStackTop(stack));
    
    printf("Pop: %d\n", myStackPop(stack));
    printf("After pop, Top: %d\n", myStackTop(stack));
    
    printf("Pop: %d\n", myStackPop(stack));
    printf("Pop: %d\n", myStackPop(stack));
    printf("After all pops, Empty: %s\n", myStackEmpty(stack) ? "true" : "false");
    
    myStackFree(stack);
    return 0;
}
