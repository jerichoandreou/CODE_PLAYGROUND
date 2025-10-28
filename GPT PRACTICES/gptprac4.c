#include <stdio.h>

#define SIZE 8

void symmetricDifference(int A[], int B[], int result[]) {
    // TODO: result[i] = (A[i] != B[i])
    for(int i = 0;i < SIZE;i++){
        result[i] = (A[i] != B[i]);
    }
}

void complementSet(int A[], int result[]) {
    // TODO: result[i] = !A[i]
    for(int i = 0;i < SIZE;i++){
        result[i] = !A[i];
    }
}

void display(int set[]) {
    for (int i = 0; i < SIZE; i++) printf("%d ", set[i]);
    printf("\n");
}

int main() {
    int A[SIZE] = {1,0,1,0,1,0,0,1};
    int B[SIZE] = {0,1,1,1,0,0,1,0};
    int result[SIZE];

    printf("A ⊕ B: "); symmetricDifference(A, B, result); display(result);
    printf("¬A: "); complementSet(A, result); display(result);
}
