#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} *SET;

typedef SET Dictionary[MAX];

void initDict(Dictionary D) {
    // TODO: Set all buckets to NULL
    for(int i = 0;i < MAX;i++){
        D[i] = NULL;
    }
}

int hash(int elem) {
    // TODO: Return ones digit of elem
}

int main() {
    Dictionary D;
    initDict(D);
    printf("Hash(27) = %d\n", hash(27));
    printf("Hash(93) = %d\n", hash(93));
}
