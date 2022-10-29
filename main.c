#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackList.h"


// --------------- FONCTIONS AUXILIAIRES TESTS
bool egales(struct Stack* l1, struct Stack* l2){

    if((l1==NULL) && (l2==NULL)){
        return true;
    }
    if((l1!=NULL) && (l2!=NULL) && (l1->liste->size == l2->liste->size)){
        struct Cell* c1 = l1->liste->head;
        struct Cell* c2 = l2->liste->head;
        while(c1 != NULL && c2 != NULL){
            if(c1->value == c2->value){
                c1 = c1->next;
                c2 = c2->next;
            }else{
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

struct Stack* StackTab(int T[], int size){
    struct Stack* l = createEmptyStack();
    struct Cell* ptr = createCell(T[0]);
    l->liste->head = ptr;
    l->liste->size = size;
    for(int i=1;i <= size-1;i++){
        ptr->next = createCell(T[i]);
        ptr = ptr->next;
    }
    return l;
}



// ----------------- TESTS ------------------------
void tests(){

    bool valid;
    int n;

    //    void push(struct Stack* s, int item, bool* valid);
    printf("-------push-------\n");
    struct Stack* L1 = createEmptyStack();
    int Tab1[1] = {2};
    struct Stack* L2 = StackTab(Tab1,1);
    push(L1,2, &valid);

    if(egales(L1,L2) && valid == true){
        printf("test push liste vide ok :D\n");
    }
    else{
        printf("test push liste vide not ok :(\n");
    }
    deleteStack(L1);
    deleteStack(L2);

    struct Stack* L3 = createEmptyStack();
    struct Stack* L4 = NULL;
    int Tab2[5] = {1,3,5,7,9};
    L4 = StackTab(Tab2,5);
    push(L3,9, &valid);
    push(L3,7, &valid);
    push(L3,5, &valid);
    push(L3,3, &valid);
    push(L3,1, &valid);
    if(egales(L3,L4)){
        printf("test push liste non vide ok :D\n");
    }
    else{
        printf("test push liste non vide not ok :(\n");
    }
    deleteStack(L3);
    deleteStack(L4);
    //--------------------------------------

    // int top(struct Stack* s, bool* valid);
    printf("-------top-------\n");
    struct Stack* L5 = createEmptyStack();
    top(L5, &valid);
    if(!valid){
        printf("test top liste vide ok :D\n");
    }
    else{
        printf("test top liste vide not ok :(\n");
    }
    push(L5,4, &valid);
    int result = top(L5, &valid);
    if(result == 4 && valid){
        printf("test top liste un element ok :D\n");
    }
    else{
        printf("test top liste un element not ok :(\n");
    }
    push(L5,5, &valid);
    push(L5,3, &valid);
    push(L5,32, &valid);
    push(L5,15, &valid);
    result = top(L5, &valid);
    if(result == 15 && valid){
        printf("test top liste plusieurs elements ok :D\n");
    }
    else{
        printf("test top liste plusieurs elements not ok :(\n");
    }
    deleteStack(L5);
    //--------------------------------------

    //    int pop(struct Stack* s, bool* valid);
    printf("-------pop-------\n");
    struct Stack* l8 = createEmptyStack();
    pop(l8, &valid);
    if(valid == false) {
        printf("test pop liste vide ok :D\n");
    }
    else{
        printf("test pop liste vide not ok :(\n");
    }
    deleteStack(l8);
    int T8[5] = {2,10,50,99,114};
    struct Stack* l81 = StackTab(T8,5);
    result = pop(l81, &valid);
    if(valid==true) {
        if(result==2 && top(l81, &valid) == 10){
            printf("test pop liste non vide ok :D\n");
        }
        else{
            printf("test pop liste non vide not ok :(\n");
        }
    }
    else{
        printf("test pop liste non vide not ok :(\n");
    }

    deleteStack(l81);
//    //--------------------------------------
//
//    //    int stackSize(struct Stack* s);
    printf("-------stackSize-------\n");
    struct Stack* L11 = createEmptyStack();
    if(stackSize(L11) == 0){
        printf("test stackSize liste vide ok :D\n");
    }
    else{
        printf("test stackSize liste vide not ok :(\n");
    }
    push(L11,9, &valid);
    if(stackSize(L11) == 1){
        printf("test stackSize liste un element ok :D\n");
    }
    else{
        printf("test stackSize liste un element not ok :(\n");
    }

    push(L11,9, &valid);
    push(L11,7, &valid);
    push(L11,5, &valid);
    push(L11,3, &valid);
    push(L11,1, &valid);
    push(L11,0, &valid);
    if(stackSize(L11) == 7){
        printf("test stackSize liste plusieurs elements ok :D\n");
    }
    else{
        printf("test stackSize liste plusieurs elements not ok :(\n");
    }
    deleteStack(L11);
//    //--------------------------------------
//
//    //    void printStack(struct Stack* s);
    printf("-------printStack-------\n");
    struct Stack* l60 = createEmptyStack();
    printf("test printStack liste vide\n *Si votre sorti est: NULL <- top\n *dans la prochaine ligne alors c'est bon :D\n");
    printStack(l60);
    deleteStack(l60);
    int T6[5] = {2,10,50,99,114};
    struct Stack* l6 = StackTab(T6,5);
    printf("test printList liste non vide\n *Si votre sorti est: \n2 <- top\n10\n50\n99\n114\n *dans la prochaine ligne alors c'est bon :D\n");
    printStack(l6);
    deleteStack(l6);
    //--------------------------------------

    //    bool isStackEmpty(struct Stack* s);
    printf("-------isStackEmpty-------\n");
    struct Stack* l7 = createEmptyStack();
    if(isStackEmpty(l7)) {
        printf("test isStackEmpty liste vide ok :D\n");
    }
    else{
        printf("test isStackEmpty liste vide not ok :(\n");
    }
    deleteStack(l7);
    int T7[5] = {2,10,50,99,114};
    struct Stack* l71 = StackTab(T7,5);
    if(!isStackEmpty(l71)) {
        printf("test isStackEmpty liste non vide ok :D\n");
    }
    else{
        printf("test isStackEmpty liste non vide not ok :(\n");
    }
    deleteStack(l71);
//    //--------------------------------------
//
//    //    deleteStack(struct Stack* q);
    printf("-------deleteStack-------\n");
    printf("executer: valgrind --tool=memcheck <nom_programme> :D\n");
    printf("TOUTES les listes utilises dans ces tests seront effacées avec cette fonction!\n");
    //--------------------------------------

}


int main(){

    tests();

    return 0;
}


/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackList.h"


// --------------- FONCTIONS AUXILIAIRES TESTS
bool egales(struct Stack* l1, struct Stack* l2){

    if((l1==NULL) && (l2==NULL)){
        return true;
    }
    if((l1!=NULL) && (l2!=NULL) && (l1->liste->size == l2->liste->size)){
        struct Cell* c1 = l1->liste->head;
        struct Cell* c2 = l2->liste->head;
        while(c1 != NULL && c2 != NULL){
            if(c1->value == c2->value){
                c1 = c1->next;
                c2 = c2->next;
            }else{
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

struct Stack* StackTab(int T[], int size){
    struct Stack* l = createEmptyStack();
    struct Cell* ptr = createCell(T[0]);
    l->liste->head = ptr;
    l->liste->size = size;
    for(int i=1;i <= size;i++){
        ptr->next = createCell(T[i]);
        ptr = ptr->next;
    }
    return l;
}



// ----------------- TESTS ------------------------
void tests(){

    bool valid;
    int n;

    //    void push(struct Stack* s, int item, bool* valid);
    printf("-------push-------\n");
    struct Stack* L1 = createEmptyStack();
    struct Stack* L2 = NULL;
    int Tab1[1] = {2};
    L2 = StackTab(Tab1,1);
    push(L1,2, &valid);

    if(egales(L1,L2) && valid == true){
        printf("test push liste vide ok :D\n");
    }
    else{
        printf("test push liste vide not ok :(\n");
    }

    struct Stack* L3 = createEmptyStack();
    struct Stack* L4 = NULL;
    int Tab2[5] = {1,3,5,7,9};
    L4 = StackTab(Tab2,5);
    push(L3,9, &valid);
    push(L3,7, &valid);
    push(L3,5, &valid);
    push(L3,3, &valid);
    push(L3,1, &valid);
    if(egales(L3,L4)){
        printf("test push liste non vide ok :D\n");
    }
    else{
        printf("test push liste non vide not ok :(\n");
    }
    deleteStack(L1);
    deleteStack(L2);
    deleteStack(L3);
    deleteStack(L4);
    //--------------------------------------

    // int top(struct Stack* s, bool* valid);
    printf("-------top-------\n");
    struct Stack* L5 = createEmptyStack();
    top(L5, &valid);
    if(!valid){
        printf("test top liste vide ok :D\n");
    }
    else{
        printf("test top liste vide not ok :(\n");
    }
    push(L5,4, &valid);
    int result = top(L5, &valid);
    if(result == 4 && valid){
        printf("test top liste un element ok :D\n");
    }
    else{
        printf("test top liste un element not ok :(\n");
    }
    push(L5,5, &valid);
    push(L5,3, &valid);
    push(L5,32, &valid);
    push(L5,15, &valid);
    result = top(L5, &valid);
    if(result == 15 && valid){
        printf("test top liste plusieurs elements ok :D\n");
    }
    else{
        printf("test top liste plusieurs elements not ok :(\n");
    }
    deleteStack(L5);
    //--------------------------------------

    //    int pop(struct Stack* s, bool* valid);
    printf("-------pop-------\n");
    struct Stack* l8 = createEmptyStack();
    pop(l8, &valid);
    if(valid == false) {
        printf("test pop liste vide ok :D\n");
    }
    else{
        printf("test pop liste vide not ok :(\n");
    }
    deleteStack(l8);
    int T8[5] = {2,10,50,99,114};
    struct Stack* l81 = StackTab(T8,5);
    result = pop(l81, &valid);
    if(valid==true) {
        if(result==2 && top(l81, &valid) == 10){
            printf("test pop liste non vide ok :D\n");
        }
        else{
            printf("test pop liste non vide not ok :(\n");
        }
    }
    else{
        printf("test pop liste non vide not ok :(\n");
    }

    deleteStack(l81);
//    //--------------------------------------
//
//    //    int stackSize(struct Stack* s);
    printf("-------stackSize-------\n");
    struct Stack* L11 = createEmptyStack();
    if(stackSize(L11) == 0){
        printf("test stackSize liste vide ok :D\n");
    }
    else{
        printf("test stackSize liste vide not ok :(\n");
    }
    push(L11,9, &valid);
    if(stackSize(L11) == 1){
        printf("test stackSize liste un element ok :D\n");
    }
    else{
        printf("test stackSize liste un element not ok :(\n");
    }

    push(L11,9, &valid);
    push(L11,7, &valid);
    push(L11,5, &valid);
    push(L11,3, &valid);
    push(L11,1, &valid);
    push(L11,0, &valid);
    if(stackSize(L11) == 7){
        printf("test stackSize liste plusieurs elements ok :D\n");
    }
    else{
        printf("test stackSize liste plusieurs elements not ok :(\n");
    }
    deleteStack(L11);
//    //--------------------------------------
//
//    //    void printStack(struct Stack* s);
    printf("-------printStack-------\n");
    struct Stack* l60 = createEmptyStack();
    printf("test printStack liste vide\n *Si votre sorti est: NULL <- top\n *dans la prochaine ligne alors c'est bon :D\n");
    printStack(l60);
    deleteStack(l60);
    int T6[5] = {2,10,50,99,114};
    struct Stack* l6 = StackTab(T6,5);
    printf("test printList liste non vide\n *Si votre sorti est: \n2 <- top\n10\n50\n99\n114\n *dans la prochaine ligne alors c'est bon :D\n");
    printStack(l6);
    deleteStack(l6);
    //--------------------------------------

    //    bool isStackEmpty(struct Stack* s);
    printf("-------isStackEmpty-------\n");
    struct Stack* l7 = createEmptyStack();
    if(isStackEmpty(l7)) {
        printf("test isStackEmpty liste vide ok :D\n");
    }
    else{
        printf("test isStackEmpty liste vide not ok :(\n");
    }
    deleteStack(l7);
    int T7[5] = {2,10,50,99,114};
    struct Stack* l71 = StackTab(T7,5);
    if(!isStackEmpty(l71)) {
        printf("test isStackEmpty liste non vide ok :D\n");
    }
    else{
        printf("test isStackEmpty liste non vide not ok :(\n");
    }
    deleteStack(l71);
//    //--------------------------------------
//
//    //    deleteStack(struct Stack* q);
    printf("-------deleteStack-------\n");
    printf("executer: valgrind --tool=memcheck <nom_programme> :D\n");
    printf("TOUTES les listes utilises dans ces tests seront effacées avec cette fonction!\n");
    //--------------------------------------

}


int main(){

    tests();

    return 0;
}
*/

