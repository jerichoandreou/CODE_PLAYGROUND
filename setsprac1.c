#include <stdio.h>
#include <stdlib.h>
#define MAX 8

void printSet(int set[]){
    for(int i = 0;i < MAX;i++){
        printf("%d ",set[i]);
    }
    printf("\n");
}

void unionSet(int A[],int B[],int result[]){
    for(int i = 0;i < MAX;i++){
        result[i] = (A[i] || B[i]);
    }
}

void intersectionSet(int A[],int B[],int result[]){
    for(int i = 0;i < MAX;i++){
        result[i] = (A[i] && B[i]);
    }
}

void differenceSet(int A[],int B[],int result[]){
    for(int i = 0;i < MAX;i++){
        result[i] = (A[i] && !B[i]); 
    }
}

int main(void){
    int A[MAX] = {0,1,1,0,1,0,0,1};
    int B[MAX] = {1,0,1,1,0,0,1,0};
    int result[MAX];
    printf("Set A: ");
    printSet(A);
    printf("Set B: ");
    printSet(B);
    unionSet(A,B,result);
    printf("\nA ∪ B = ");
    printSet(result);
    intersectionSet(A,B,result);
    printf("\nA & B = ");
    printSet(result);  
    
    return 0;
}