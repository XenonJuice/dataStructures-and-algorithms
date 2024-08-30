//
// Created by user on 2024/8/8.
//
#ifndef STACK_H
#define STACK_H
#define null NULL
#include "AVL_TREE.h"

typedef struct Stack Stack;
typedef struct AVL_TreeNode AVL_TreeNode;


typedef struct Stack {
    AVL_TreeNode *node;
    Stack *next;
} Stack;

void push(Stack **stack, AVL_TreeNode *node);

void *pop(Stack **stack);

void *peek(const Stack *stack);

bool isEmptyStack(const Stack *stack);

void printStack(const Stack *stack);

__attribute__((deprecated("无意义的创建了一个包含有哑节点的栈指针，输出栈内容时会导致nullptr,直接声明栈节点为NULL即可")))
Stack *createStack();

void destoryStack(Stack *stack);

void destoryTree(AVL_TreeNode *root);
#endif //STACK_H
