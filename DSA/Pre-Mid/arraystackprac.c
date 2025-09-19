#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack S;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack* s);
void display(Stack* s);

int main(void){
    Stack* s = initialize();
    push(s,10);
    push(s,69);
    push(s,20);
    display(s);
    printf("\nThe popped value is: %d",pop(s));
    display(s);
    printf("\nCurrent top value from peek: \n%d",peek(s));
    display(s);
    return 0;
}

Stack* initialize(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s){
    return s->top == MAX;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s,int value){
    if(isFull(s)){
        printf("Stack is full");
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
    }
    int poppedValue = s->items[s->top];
    s->top--;
    return poppedValue;
}

int peek(Stack* s){
    int peekVal = s->items[s->top];
    return peekVal;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
    }
    printf("\nStack top to bottom: \n");
    for(int i = s->top;i >= 0;i--){
        printf("%d ",s->items[i]);
    }
}
