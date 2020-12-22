//
// Created by fox on 2020/11/11.
//
typedef int  ElementType;
#ifndef _Stack_h
#define _Stack_h
struct Node;
typedef struct Node* PtrToNode;
typedef  PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void Push(ElementType X, Stack S);
void Pop(Stack S);
ElementType Top(Stack S);
void MakeEmpty(Stack S);

#endif


