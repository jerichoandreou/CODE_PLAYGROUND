#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int front;
    int rear;
}Queue;

Queue q;

Queue* initialize();

int main(void){
    Queue* q = initialize();

    return 0;
}

Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
}

bool isEmpty(Queue* q){
    return q->front == (rear + 1) % MAX;
}//still need to understand why this

bool isFull(Queue* q){
    return q->rear == (rear + 2) % MAX;
}