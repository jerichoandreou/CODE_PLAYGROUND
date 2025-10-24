#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    unsigned int field: 8;
} Set;

void initialize(Set *set){
    set->field = 0;
}
void insert(Set *set,int element){
    if(element < 0 || element > 7) return;
    set->field |= (1 << element);
}

void delete(Set *set,int element){
    if(element < 0 || element > 7) return;
    set->field &= ~(1 << element);
}

bool find(Set set,int element){
    return (set.field & (1 << element)) != 0;
}

Set unionSet(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set intersectionSet(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set difference(Set A, Set B){
    Set result;
    result.field = A.field & (~B.field);
    return result;
}

void display(Set set){
    for(int i = 1;i <= 7;i++){
        if(find(set,i)){
            printf("%d ",i);
        }
    }
}
int main(void){

    
    return 0;
}

