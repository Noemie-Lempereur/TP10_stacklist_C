#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackList.h"


struct Stack* createEmptyStack(){
    struct Stack* stack =malloc(sizeof(struct Stack));
    if (stack!=NULL){
        stack->liste=createEmptyList();
    }
    return stack;
}

void push(struct Stack* s, int item, bool* valid){
    if(s!=NULL) {
        addFirst(s->liste, item);
        *valid=true;
        return;
    }
    *valid=false;
}

int top(struct Stack* s, bool* valid){
    if(isStackEmpty(s)==false) {
        int a;
        bool b = 0;
        bool* vali=&b;
        a=getItemPos(s->liste, 0, vali);
        if(b==false){
            *valid=false;
            return -1;
        }
        *valid=true;
        return a;
    }
    *valid=false;
    return -1;
}

int pop(struct Stack *s, bool* valid){
    if(s!=NULL) {
        int a;
        bool b = true;
        bool *vali = &b;
        a = top(s, vali);
        if (*vali == true) {
            *valid = true;
            deleteFirst(s->liste);
            return a;
        }
    }
    *valid=false;
    return -1;
}

int stackSize(struct Stack* s){
    if(s!=NULL){
        return s->liste->size;
    }
    return -1;
}

bool isStackEmpty(struct Stack* s){
    if(s!=NULL){
        if(stackSize(s)==0){
            return true;
        }
        return false;
    }
    return false;
}

void printStack(struct Stack* s){
    if(s != NULL){
        bool valid = true;
        for(int i = 0; i < stackSize(s); i++){
            printf("%d ", getItemPos(s->liste, i, &valid));
            if(i == 0){
                printf("<- top");
            }
            printf("\n");
        }
        if(isStackEmpty(s)){
            printf("NULL <- top\n");
        }
    }
}

void deleteStack(struct Stack* q){
    if(q!=NULL) {
        deleteList(q->liste);
        free(q);
    }
}