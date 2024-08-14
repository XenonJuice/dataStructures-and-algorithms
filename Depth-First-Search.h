//
// Created by user on 2024/8/8.
//
#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H
#include "STACK.h"

//前，中，后序遍历
void preOrderTraversal(const TreeNode *root, Stack *stack);

void inOrderTraversal(const TreeNode *root, Stack *stack);

void postOrderTraversal(const TreeNode *root, Stack *stack);
#endif //DEPTH_FIRST_SEARCH_H
