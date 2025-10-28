#include <stdio.h>

#define SIZE 8

void unionSet(int A[], int B[], int result[]) {
    // TODO: result[i] = (A[i] || B[i])
    for(int i = 0;i < SIZE;i++){
        result[i] = (A[i] || B[i]);
    }
}

void intersectionSet(int A[], int B[], int result[]) {
    // TODO: result[i] = (A[i] && B[i])
    for(int i = 0;i < SIZE;i++){
        result[i] = (A[i] && B[i]);
    }
}

void differenceSet(int A[], int B[], int result[]) {
    // TODO: result[i] = (A[i] && !B[i])
    for(int i = 0;i < SIZE;i++){
        result[i] = (A[i] && !B[i]);
    }
}

void display(int set[]) {
    for (int i = 0; i < SIZE; i++) printf("%d ", set[i]);
    printf("\n");
}

int main() {
    int A[SIZE] = {0,0,1,0,1,0,0,1};
    int B[SIZE] = {1,0,1,0,0,1,0,0};
    int result[SIZE];

    printf("A ∪ B: "); unionSet(A, B, result); display(result);
    printf("A ∩ B: "); intersectionSet(A, B, result); display(result);
    printf("A - B: "); differenceSet(A, B, result); display(result);
}
