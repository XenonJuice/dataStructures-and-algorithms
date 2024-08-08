//
// Created by user on 2024/8/8.
//
#include "STACK.h"
#include <stdio.h>
#include <stdlib.h>

/* @brief 出栈
 * @param stack 指向栈指针的指针，通过该指针修改栈顶的指向
 * @return 返回栈顶节点
 */
const TreeNode *pop(Stack **stack) {
    if(isEmpty(*stack)) return null;
    const Stack *tmp =*stack;
    *stack =(*stack)->next;
    const TreeNode * returnNode = tmp->node;
    free((void*)tmp);
    return returnNode;
}
/* @brief 入栈
 * @param node 指向传入新增节点的指针，该节点需要入栈
 * @param stack 指向栈指针的指针，通过该指针可以修改栈顶的指向
 */
void push(Stack **stack, const TreeNode *node) {
    Stack *new_node =(Stack *)malloc(sizeof(Stack));
    new_node->node = node;
    new_node->next=*stack;
    *stack=new_node;
}
/* @brief 访问栈顶元素
 * @param stack 指向栈的指针，通过该指针可以访问栈顶元素
 */
const TreeNode *peek(const Stack *stack) {
    const TreeNode * topStackNode = stack->node;
    return topStackNode;
}
/* @brief 检查栈是否为空
 * @param stack 指向栈的指针，通过该指针可以访问栈顶元素
 */
bool isEmpty(const Stack *stack) {
    return stack==null;
}
/* @brief 输出栈的元素
 * @param stack 指向栈的指针，通过该指针可以访问栈顶元素
 */
void printStack(const Stack *stack) {
    const Stack *tmp =stack;
    while(!isEmpty(tmp)) {
        printf("%d —>", tmp->node->val);
        tmp =tmp->next;
    }
    free((void*)tmp);
}
// @brief 创建一个空栈
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack ==null) {printf("malloc error");return null;}
    stack->next=null;
    stack->node=null;
    return stack;
}
// @brief 销毁栈
void destoryStack(Stack *stack) {
    if (isEmpty(stack)) {printf("stack is NULL");return;}
    while(!isEmpty(stack)) {
        pop(&stack);
    }
    printf("destory stack\n");
}
// @brief 创建一个树节点
TreeNode *createTreeNode(int val) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node ==null) {printf("malloc error");return null;}
    node->val = val;
    node->left =null;
    node->right =null;
    return node;
}
// @brief 创建一个树结构
TreeNode *createTreeStructure(int val, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node ==null) {printf("malloc error");return null;}
    node->val = val;
    node->left =left;
    node->right =right;
    return node;
}

// @brief 销毁树结构
void destoryTree(TreeNode *root) {
    if (root ==null) {printf("root is NULL");return;}
    if (root->left !=null) {
        destoryTree(root->left);
    }
    if (root->right !=null) {
        destoryTree(root->right);
    }
    printf("destory node %d\n", root->val);
    free(root);
    printf("destory tree\n");
}