//
// Created by user on 2024/8/8.
//
#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H
#include "STACK.h"

//前，中，后序遍历
void preOrderTraversal(AVL_TreeNode *root, Stack *stack);

void inOrderTraversal(AVL_TreeNode *root, Stack *stack);

void postOrderTraversal(AVL_TreeNode *root);
#endif //DEPTH_FIRST_SEARCH_H
