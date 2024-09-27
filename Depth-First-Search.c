//
// Created by user on 2024/8/8.
//
#include "Depth-First-Search.h"
#include <stddef.h>
#include <stdio.h>
#include "STACK.h"
//前，中，后序遍历

// root->left->right
void preOrderTraversal(AVL_TreeNode *root, Stack *stack) {
    if (root == null) {
        printf("preOrderTraversal : root is NULL\n");
        return;
    }
    printf("前序遍历 开始\n");
    // push rootNode into stack
    push(&stack, root);
    while (!isEmptyStack(stack)) {
        const AVL_TreeNode *tmp = pop(&stack);
        printf("%d —> ", tmp->val);
        // 将根节点的右子节点入栈
        if (tmp->right != null) {
            push(&stack, tmp->right);
        }
        // 将根节点的左子节点入栈
        if (tmp->left != null) {
            push(&stack, tmp->left);
        }
    }
}

// left->root->right
void inOrderTraversal(AVL_TreeNode *root, Stack *stack) {
    if (root == null) {
        printf("inOrderTraversal : root is NULL\n");
        return;
    }
    printf("中序遍历 开始\n");
    // push rootNode into stack
    AVL_TreeNode *current = root;
    while (current || !isEmptyStack(stack)) {
        while (current) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d —> ", current->val);
        current = current->right;
    }
}

// left->right->root
void postOrderTraversal(AVL_TreeNode *root) {
    if (root == null) {
        printf("postOrderTraversal : root is NULL\n");
        return;
    }
    printf("后序遍历 开始\n");
    Stack *stack1 = NULL;
    Stack *stack2 = NULL;
    push(&stack1, root);
    while (!isEmptyStack(stack1)) {
        AVL_TreeNode *tmp = pop(&stack1);
        push(&stack2, tmp);
        if (tmp->left) push(&stack1, tmp->left);
        if (tmp->right) push(&stack1, tmp->right);
    }
    while (!isEmptyStack(stack2)) {
        AVL_TreeNode *tmp = pop(&stack2);
        printf("%d —> ", tmp->val);
    }
}
