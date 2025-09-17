#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
//Array Queue
//Insertion is done on one side, deletion is done on the other (FRONT & REAR).
//FIRST IN FIRST OUT
//LAST IN LAST OUT
typedef struct{
    int items[MAX];
    int count;
}List;
typedef struct{
    List list;
    int front;
    int rear;
}Queue;
Queue q;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void display(Queue* q);
void enqueue(Queue* q,int value);
int dequeue(Queue* q);
int front(Queue* q);

int main(void){
    Queue* q = initialize();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    display(q);
    
    printf("\n\nValue that was removed:\n%d\n\n",dequeue(q));
    display(q);
    int frontValue = front(q);
    printf("\n\nValue of the front of the queue:\n%d\n\n",frontValue);
    return 0;
}

Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q){
    return q->list.count == MAX;
}

bool isEmpty(Queue* q){
    return q->list.count == 0;
}

void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("List is full");
        return;
    }else if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }else{
        q->rear = (q->rear + 1) % MAX;
    }
        q->list.items[q->rear] = value;
        q->list.count++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
    }
    int temp = q->list.items[q->front];
    if(q->list.count == 1){//if this is the last element in the queue then reset the initial list back to its empty state
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = (q->front + 1) % MAX;
    }
        q->list.count--;
        return temp;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("List is empty");
    }
    return q->list.items[q->front];

}

void display(Queue* q){
    if(isEmpty(q)){
        printf("List is empty");
    }
    int index = q->front;
    printf("Queue from first to last:\n");
    for(int i = 0;i < q->list.count;i++){
        printf("%d ",q->list.items[index]);
        index = (index + 1) % MAX;
    }
}
