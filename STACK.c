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
void *pop(Stack **stack) {
    if (isEmptyStack(*stack)) return null;
    Stack *tmp = *stack;
    *stack = (*stack)->next;
    void *returnNode = tmp->node;
    free(tmp);
    return returnNode;
}

/* @brief 入栈
 * @param node 指向传入新增节点的指针，该节点需要入栈
 * @param stack 指向栈指针的指针，通过该指针可以修改栈顶的指向
 */
void push(Stack **stack, AVL_TreeNode *node) {
    Stack *new_node = (Stack *) malloc(sizeof(Stack));
    new_node->node = node;
    new_node->next = *stack;
    *stack = new_node;
}

/* @brief 访问栈顶元素
 * @param stack 指向栈的指针，通过该指针可以访问栈顶元素
 */
void *peek(const Stack *stack) {
    void *topStackNode = stack->node;
    return topStackNode;
}

/* @brief 检查栈是否为空
 * @param stack 指向栈的指针，通过该指针可以访问栈顶元素
 */
bool isEmptyStack(const Stack *stack) {
    return stack == null;
}

/* @brief 输出栈的元素
 * @param stack 指向栈的指针，通过该指针可以访问栈顶元素
 */
void printStack(const Stack *stack) {
    printf("print out the stack\n");
    const Stack *tmp = stack;
    while (!isEmptyStack(tmp)) {
        printf("%d -> ", tmp->node->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// @brief 创建一个空栈
__attribute__((deprecated(
    "无意义的创建了一个包含有哑节点的栈指针，输出栈内容时会导致nullptr,直接声明栈节点为NULL即可")))
Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == null) {
        printf("malloc error");
        return null;
    }
    stack->next = null;
    stack->node = null;
    return stack;
}

// @brief 销毁栈
void destoryStack(Stack *stack) {
    if (isEmptyStack(stack)) {
        printf("\ndestoryStack : stack is NULL\n");
        return;
    }
    while (!isEmptyStack(stack)) {
        pop(&stack);
    }
    printf("destory stack\n");
}

// // @brief 创建一个树节点
// TreeNode *createTreeNode(int val) {
//     TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
//     if (node == null) {
//         printf("malloc error\n");
//         return null;
//     }
//     node->val = val;
//     node->left = null;
//     node->right = null;
//     return node;
// }

// // @brief 创建一个树结构
// TreeNode *createTreeStructure(TreeNode *root, TreeNode *left, TreeNode *right) {
//     TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
//     if (node == null) {
//         printf("malloc error");
//         return null;
//     }
//     node=root;
//     node->left = left;
//     node->right = right;
//     return node;
// }
//
// // @brief 输出树的元素
// void printTree(void *root) {
//     if (root == null) {
//         printf("root is NULL");
//         return;
//     }
//     printf("%d —>", root->val);
//     if (root->left != null) {
//         printTree(root->left);
//     }
//     if (root->right != null) {
//         printTree(root->right);
//     }
//     printf("NULL\n");
// }
//
// // @brief 销毁树结构
// void destoryTree(TreeNode *root) {
//     if (root == null) {
//         printf("root is NULL");
//         return;
//     }
//     if (root->left != null) {
//         destoryTree(root->left);
//     }
//     if (root->right != null) {
//         destoryTree(root->right);
//     }
//     printf("destory node %d\n", root->val);
//     free(root);
// }
