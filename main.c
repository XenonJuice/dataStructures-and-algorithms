//
// Created by user on 2024/7/30.
//
#include <stdio.h>
#include <stdlib.h>

#include "AVL_TREE.h"


int main() {
    system("chcp 65001");
    printf("Hello, Excel!\n");
    // test the avl tree
    AVL_TreeNode *root = NULL;
    for (int i = 0; i < 20; i++) {
        root = insert(root, i);
    }
    bfs(root);
    printTree(root, 0);
    destroyAVLTree(root);

    getchar();
    return 0;
}


