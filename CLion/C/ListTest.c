//
// Created by fox on 2020/11/3.
//
//ifndef _List_H
#include "stdlib.h"
#include "fatal.h"
#include "list.h"
struct Node {
    ElementType Element;
    Position Next;
};

int IsEmpty(List L)
{
 return L->Next == NULL;
}

//return true if P is the last position in List L
int IsLast(Position P, List L) {
    return P->Next == NULL;
}

//return position of X in L;NULL if not found
Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while (P->Next != NULL && P->Element != NULL) {
        P = P->Next;
    }
    return P;
}

/*
 * if X is not found ,the next field is returned
 * Position is NULL
 * Assumes a header
 */
Position FindPrevious(ElementType X, List L) {
    Position  P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X) {}
    P = P->Next;
}

void Delete(ElementType X, List L) {
    Position P, TemCell;
    P = FindPrevious(X,L);
    if (!IsLast(P,L)) {
        TemCell = P->Next;
        P->Next = TemCell->Next;
        free(TemCell);
    }
}

void Insert(ElementType X, List L, Position P)  {
    Position TemCell;
    TemCell = malloc(sizeof(struct Node));
    if (TemCell == NULL){
        FatalError("out of space");
    }
    TemCell->Next = P->Next;
    TemCell->Element = X;
    P->Next = TemCell;
}




