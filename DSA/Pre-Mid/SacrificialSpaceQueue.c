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
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q,int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

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
    return q->front == (q->rear + 1) % MAX;
}//still need to understand why this

bool isFull(Queue* q){
    return q->rear == (q->rear + 2) % MAX;
}

void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("List is full");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
    }
    
}