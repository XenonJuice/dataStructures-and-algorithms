//
// Created by user on 2024/7/30.
//
#include <stdio.h>
#include <stdlib.h>

#include "AVL_TREE.h"
#include "Queue.h"
#include "Heap.h"
#include "STACK.h"
#include "ArrayList.h"


int main() {
    system("chcp 65001");
    printf("Hello, Excel!\n");
    // test the avl tree
    // AVL_TreeNode *root = NULL;
    // for (int i = 0; i < 20; i++) {
    //     root = insert(root, i);
    // }
    // bfs(root);
    // printTree(root, 0);
    // destroyAVLTree(root);

    // test the arraylist
    // ArrayList *list = initArrayList(10);
    // for (int i = 20; i > 0; i--) {
    //     add(list, i);
    // }

    //test the heap
    Heap *heap = heap_create(10);
    for (int i = 20; i > 0; i--) {
        heap_insert(heap, i);
    }
    heap_print(heap);
    heap_print(heap);

    heap_insert(heap, 0);
    heap_print(heap);
    heap_insert(heap, 0);
    heap_insert(heap, 99);
    heap_insert(heap, 50);
    heap_insert(heap, 100);
    heap_insert(heap, 21);
    heap_insert(heap, -5);
    heap_print(heap);
    heap_destroy(heap);


    getchar();
    return 0;
}


