//
// Created by user on 2024/7/30.
//
#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"
#define RANGE 20
#define TOPKSIZE 4

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
    // Heap *heap = heap_create(10);
    // for (int i = 20; i > 0; i--) {
    //     heap_insert(heap, i);
    // }
    // heap_print(heap);
    // heap_print(heap);
    // heap_insert(heap, 0);
    // heap_print(heap);
    // heap_insert(heap, 0);
    // heap_insert(heap, 99);
    // heap_insert(heap, 50);
    // heap_insert(heap, 100);
    // heap_insert(heap, 21);
    // heap_insert(heap, -5);
    // heap_print(heap);
    // heap_destroy(heap);

    // getTOPK
    // array for test [6 12 13 1 2 8 0 14 11 3 7 10 9 5 4]
    // Heap *heap = heap_create(TOPKSIZE);
    // ArrayList *listRangeOneThousand = initArrayList(RANGE);
    // for (int i = 0; i < RANGE; i++) {
    //     add(listRangeOneThousand, i);
    // }
    // shuffle(listRangeOneThousand->data, RANGE);
    // printf("GETTOPK 打印无序数组: \n");
    // printArrayList(listRangeOneThousand);
    // // 将无序数组的前topSize个元素放入堆中
    // for (int i = 0; i < TOPKSIZE; i++) {
    //     heap_insert(heap, *(listRangeOneThousand->data + i));
    // }
    // heap_init(heap); // 初始化堆(从最后一个非叶子节点开始堆化，保证所有节点都已经堆化完成)
    // printf("打印初始化后的堆: \n");
    // heap_print(heap);
    // // 遍历无序数组的后(RANGE-TOPKSIZE)个元素，如果大于堆顶元素，则将该元素替换为堆顶元素，然后堆化
    // for (int i = TOPKSIZE; i < RANGE; i++) {
    //     int foo = *(listRangeOneThousand->data + i);
    //     int heapTop = heap_peek(heap);
    //     if (foo > heapTop) {
    //         heap_delete(heap);
    //         heap_insert(heap, foo);
    //     }
    //     heap_print(heap);
    // }
    // heap_destroy(heap);
    // destroyArrayList(listRangeOneThousand);

    //测试二分查找
    ArrayList *binarySearchArrayList = initArrayList(10);
    for (int i = 0; i < 10; i++) {
        add(binarySearchArrayList, i);
    }
    printf("二分查找测试: \n");
    for (int i = 0; i < 10; i++) {
        int binarySearchResult = binarySearch(binarySearchArrayList, i);
        printf("二分查找结果: %d\n", binarySearchResult);
    }

    destroyArrayList(binarySearchArrayList);
    //getchar();

    // 冒泡排序测试
    int inttie[] = {7, 5, 6, 4, 2, 1, 3, 9, 8, 0};
    ArrayList *bubbleSortArrayList = initArrayList(10);
    for (int i = 0; i < 10; i++) {
        add(bubbleSortArrayList, inttie[i]);
    }
    printf("冒泡排序测试: \n");
    bubbleSort(bubbleSortArrayList);
    destroyArrayList(binarySearchArrayList);
    return 0;
}


