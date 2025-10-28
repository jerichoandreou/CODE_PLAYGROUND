#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

bool isMember(int set[], int element) {
    return set[element] == 1;
}

bool isSubset(int A[], int B[]) {
    for(int i = 0;i < SIZE;i++){
        if(B[i] == 1 && !A[i]){
            return false;
        }
    }
    return true;
}

int main() {
    int A[SIZE] = {1,1,0,1,0,0,0,0}; // {0,1,3}
    int B[SIZE] = {1,0,0,1,0,0,0,0}; // {0,3}

    printf("Is 1 in A? %s\n", isMember(A, 1) ? "Yes" : "No");
    printf("Is B a subset of A? %s\n", isSubset(A, B) ? "Yes" : "No");
}
//expected output:
//Is 1 in A? Yes
//Is B a subset of A? Yes