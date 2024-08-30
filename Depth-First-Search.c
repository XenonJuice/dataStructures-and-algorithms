//
// Created by user on 2024/8/8.
//
#include "Depth-First-Search.h"
#include <stddef.h>
#include <stdio.h>
#include "STACK.h"
//前，中，后序遍历
void preOrderTraversal(AVL_TreeNode *root, Stack *stack) {
    if (root == null) {
        printf("preOrderTraversal : root is NULL\n");
        return;
    }
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

void inOrderTraversal(AVL_TreeNode *root, Stack *stack);

void postOrderTraversal(AVL_TreeNode *root, Stack *stack);
