#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){
    if(element < 1 || element > 7) return;
    *set |= (1 << element);
}

void delete(unsigned char *set, int element){
    if(element < 1 || element > 7) return;
    *set &= ~(1 << element);
}

bool find(unsigned char set,int element){
    return (set & (1 << element)) != 0;
}
unsigned char unionSet(unsigned char A,unsigned char B){
    return A | B;
}

unsigned char intersectionSet(unsigned char A,unsigned char B){
    return A & B;
}

unsigned char difference(unsigned char A,unsigned char B){
    return A & (~B);
}

void display(unsigned char set){
    for(int i = 1;i <= 7;i++){
        if(find(set,i)){
            printf("%d ",i);
        }
    }
}
int main(void){
        unsigned char A;
    initialize(&A);           // {}
    insert(&A, 1);            // {1}
    insert(&A, 6);            // {1,6}
    printf("A = ");
    display(A);

    unsigned char B = 200;    // bits for {3,6,7}
    printf("B = ");
    display(B);

    unsigned char C = unionSet(A, B);
    printf("A union B = ");
    display(C);

    unsigned char I = intersectionSet(A, B);
    printf("A intersection B = ");
    display(I);

    unsigned char D = difference(A, B);
    printf("A \\ B = ");
    display(D);

    delete(&A, 1);
    printf("A after deleting 1 = ");
    display(A);

    return 0;


    return 0;
}