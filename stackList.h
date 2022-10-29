

#ifndef TP10_STACKLIST_H
#define TP10_STACKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

struct Stack{
    struct List* liste;
};

struct Stack* createEmptyStack();

void push(struct Stack* s, int item, bool* valid);

int top(struct Stack* s, bool* valid);

int pop(struct Stack *s, bool* valid);

int stackSize(struct Stack* s);

bool isStackEmpty(struct Stack* s);

void printStack(struct Stack* s);

void deleteStack(struct Stack* q);

#endif