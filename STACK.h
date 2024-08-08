//
// Created by user on 2024/8/8.
//
#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#define null NULL
typedef struct TreeNode TreeNode;
typedef struct Stack Stack;
typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

typedef struct Stack{
    const TreeNode *node;
    Stack *next;
}Stack;
void push(Stack **stack, const TreeNode *node);
const TreeNode *pop(Stack **stack);
const TreeNode *peek(const Stack *stack);
bool isEmpty(const Stack *stack);
void printStack(const Stack *stack);
Stack *createStack();
void destoryStack(Stack *stack);
TreeNode *createTreeNode(int val);
TreeNode *createTreeStructure(int val, TreeNode *left, TreeNode *right);
void destoryTree(TreeNode *root);
void printTree(const TreeNode *root);

#endif //STACK_H
