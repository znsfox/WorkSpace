//
// Created by fox on 2020/11/11.
//
#include <malloc.h>
#include "stack.h"
#include "stdlib.h"
#include "../fatal.h"

struct Node {
    ElementType elementType;
    PtrToNode Next;
};

int IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void) {
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S = NULL) {
        FatalError("out of space!");
    }
    S->Next == NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S) {
    if (S == NULL)
        Error("must crete stack first!");
    else
        while(!IsEmpty(S))
            Pop(S);
}

void Push(ElementType X, Stack S) {
    PtrToNode TemCell;
    TemCell = malloc(sizeof(struct Node));
    if (TemCell == NULL) {
        FatalError("out of space!!!");
    }
    TemCell->elementType = X;
    TemCell->Next = S->Next;
    S->Next = TemCell;
}

ElementType Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->elementType;
    }
    Error("stack is NUll");
    return 0;//return value used to avoid warning
}

void DisposeStack(Stack S) {
    MakeEmpty(S);
    free(S);
}

void Pop(Stack S) {
    PtrToNode FirstCell;
    if (IsEmpty(S)) {
        Error("Empty Stack");
    } else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}