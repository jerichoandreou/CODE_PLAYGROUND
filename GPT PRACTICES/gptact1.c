#include <stdio.h>

#define UNIVERSAL_SIZE 8

void createSubset(int subset[], int elements[], int size) {
    // TODO: Initialize all indices to 0
    // TODO: For each element in `elements`, set subset[element] = 1
    for(int i = 0;i < UNIVERSAL_SIZE;i++){
        subset[i] = 0;
    }
    for(int i = 0;i < size;i++){
        subset[elements[i]] = 1;
    }

}

void displaySet(int subset[]) {
    for (int i = 0; i < UNIVERSAL_SIZE; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

int main() {
    int subsetA[UNIVERSAL_SIZE];
    int elements[] = {2, 4, 7};

    createSubset(subsetA, elements, 3);
    displaySet(subsetA);

    return 0;
}
//expected output: 0 0 1 0 1 0 0 1