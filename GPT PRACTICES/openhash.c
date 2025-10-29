#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} *SET;

typedef SET Dictionary[MAX];
typedef enum {FALSE, TRUE} Boolean;

// Function prototypes
void initDict(Dictionary D);
int hash(int elem);
void displayDict(Dictionary D);
Boolean isMember(Dictionary D, int elem);
void insertUnique(Dictionary D, int elem);
void deleteMember(Dictionary D, int elem);

int main() {
    Dictionary D;
    initDict(D);

    // Insert sample data
    insertUnique(D, 21);
    insertUnique(D, 31);
    insertUnique(D, 41);
    insertUnique(D, 22);
    insertUnique(D, 32);
    insertUnique(D, 41); // duplicate test
    printf("\n");

    // Display dictionary
    displayDict(D);
    printf("\n");

    // Membership test
    printf("Is 31 in dictionary? %s\n", isMember(D, 31) ? "Yes" : "No");
    printf("Is 99 in dictionary? %s\n", isMember(D, 99) ? "Yes" : "No");
    printf("\n");

    // Deletion test
    deleteMember(D, 31);
    deleteMember(D, 99);
    printf("\n");

    displayDict(D);
    return 0;
}

/* ==============================
   FUNCTION: initDict()
   PURPOSE: Initialize all dictionary buckets to NULL
   ============================== */
void initDict(Dictionary D) {
    // ✅ CHECKLIST:
    // [ ] Loop through all indices from 0 to MAX-1
    // [ ] Set each D[i] to NULL
    for(int i = 0;i < MAX;i++){
        D[i] = NULL;
    }
}


/* ==============================
   FUNCTION: hash()
   PURPOSE: Return the bucket index using the ones digit
   ============================== */
int hash(int elem) {
    // ✅ CHECKLIST:
    // [ ] Compute the ones digit of elem (elem % 10)
    // [ ] Return the result
    int result = elem % 10;
}


/* ==============================
   FUNCTION: displayDict()
   PURPOSE: Display all buckets and their linked list contents
   ============================== */
void displayDict(Dictionary D) {
    // ✅ CHECKLIST:
    // [ ] Print "Dictionary:" heading
    // [ ] Loop through each index 0 to MAX-1
    // [ ] Print the index in [i]:
    // [ ] If D[i] == NULL → print "EMPTY"
    // [ ] Else, traverse linked list at D[i]
    // [ ] Print each data value followed by " -> " if not last node
    printf("Dictionary: \n");
    for(int i = 0;i < MAX;i++){
        printf("[%d]: ",i);
        if(D[i] == NULL){
            printf("EMPTY");
        }else{
            SET trav = D[i];
            while(trav != NULL){
                printf("%d",trav->data);
                if(trav->next != NULL){
                    printf(" -> ");
                }
                trav = trav->next;
            }
        }
        printf("\n");
    }
}


/* ==============================
   FUNCTION: isMember()
   PURPOSE: Check if an element exists in the dictionary
   ============================== */
Boolean isMember(Dictionary D, int elem) {
    // ✅ CHECKLIST:
    // [ ] Get index using hash(elem)
    // [ ] Set a traversal pointer = D[index]
    // [ ] While traversal is not NULL:
    //       → If current node's data == elem, return TRUE
    //       → Move to next node
    // [ ] If loop ends, return FALSE
    int index = hash(elem);
    SET trav = D[index];
    while(trav != NULL){
        if(trav->data == elem){
            return TRUE;
        }
        trav = trav->next;
    }
    return FALSE;
}


/* ==============================
   FUNCTION: insertUnique()
   PURPOSE: Insert an element into correct bucket (no duplicates)
   ============================== */
void insertUnique(Dictionary D, int elem) {
    // ✅ CHECKLIST:
    // [ ] Compute index = hash(elem)
    // [ ] Check if element already exists using isMember()
    //       → If TRUE, print message that element exists and return
    // [ ] Allocate memory for new node
    // [ ] Set new node’s data = elem
    // [ ] Insert node at the beginning of the linked list (head insertion)
    // [ ] Print confirmation message with bucket index
    int index = hash(elem);
    if(isMember(D,elem)){
        printf("ALREADY EXISTS\n");
    }
    SET newNode = (SET)malloc(sizeof(struct node));
    newNode->data = elem;
    newNode->next = D[index];
    D[index] = newNode;
    printf("INSERTED\n");
}


/* ==============================
   FUNCTION: deleteMember()
   PURPOSE: Delete an element from its bucket if found
   ============================== */
void deleteMember(Dictionary D, int elem) {
    // ✅ CHECKLIST:
    // [ ] Compute index = hash(elem)
    // [ ] Create two pointers: curr (current) and prev (previous)
    // [ ] Initialize curr = D[index], prev = NULL
    // [ ] Traverse while curr != NULL and curr->data != elem:
    //       → Move prev = curr
    //       → Move curr = curr->next
    // [ ] If curr == NULL → element not found → print message and return
    // [ ] If prev == NULL → element is at head → update D[index] = curr->next
    // [ ] Else → link prev->next = curr->next
    // [ ] Free the deleted node
    // [ ] Print confirmation message
    int index = hash(elem);
    SET curr = D[index];
    SET prev = NULL;
    while(curr != NULL && curr->data != elem){
        prev = curr;
        curr = curr->next;
    }if(curr == NULL){
        printf("ELEMENT NOT FOUND\n");
        return;
    }else if(prev == NULL){
        D[index] = curr->next;
    }else{
        prev->next = curr->next;
    }
    free(curr);
    printf("DELETED SUCCESS\n");
}
