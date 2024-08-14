//
// Created by user on 2024/7/30.
//
#include <stdio.h>
#include <stdlib.h>

#include "STACK.h"


int main() {
    system("chcp 65001");
    printf("Hello, Excel!\n");
    // 栈结构测试
     // Stack *testStack2 = createStack();
     // free(testStack2);
    Stack *testStack = null;
    TreeNode *tree_node_1 = createTreeNode(1);
    TreeNode *tree_node_2 = createTreeNode(2);
    TreeNode *tree_node_3 = createTreeNode(3);
    TreeNode *tree_node_4 = createTreeNode(4);
    TreeNode *tree_node_5 = createTreeNode(5);
    push(&testStack, tree_node_1);
    push(&testStack, tree_node_2);
    push(&testStack, tree_node_3);
    push(&testStack, tree_node_4);
    push(&testStack, tree_node_5);
    printStack(testStack);
    // 树结构测试
    TreeNode *root = createTreeStructure(1, tree_node_2, tree_node_3);
    printTree(root);

    destoryStack(testStack);
    destoryTree(root);
    getchar();
    return 0;
}


