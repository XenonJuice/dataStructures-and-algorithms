//
// Created by user on 2024/7/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AVL_TREE.h"
#include "Heap.h"
#include "LinkedList.h"
#define RANGE 20
#define TOPKSIZE 4
#define ARRAY_SIZE 2000
#define TOTAL_NUMBERS 1000
#define RANDOM_COUNT 100

int main() {
    system("chcp 65001");
    printf("Hello, Excel!\n");
    // test the avl tree
    AVL_TreeNode *root = NULL;
    for (int i = 0; i < 20; i++) {
        root = insert(root, i);
    }
    // 广度优先遍历
    // bfs(root);
    // 深度有限遍历前中后序
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    printTree(root, 0);
    destroyAVLTree(root);

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

    // //测试二分查找
    // ArrayList *binarySearchArrayList = initArrayList(10);
    // for (int i = 0; i < 10; i++) {
    //     add(binarySearchArrayList, i);
    // }
    // printf("二分查找测试: \n");
    // for (int i = 0; i < 10; i++) {
    //     int const binarySearchResult = binarySearch(binarySearchArrayList, i);
    //     printf("二分查找结果: %d\n", binarySearchResult);
    // }
    // destroyArrayList(binarySearchArrayList);
    //
    // // 冒泡排序测试
    // int const inttie[] = {7, 5, 6, 4, 2, 1, 3, 9, 8, 0};
    // ArrayList *bubbleSortArrayList = initArrayList(10);
    // for (int i = 0; i < 10; i++) {
    //     add(bubbleSortArrayList, inttie[i]);
    // }
    // printf("冒泡排序测试: \n");
    // bubbleSort(bubbleSortArrayList);
    // destroyArrayList(bubbleSortArrayList);
    //
    // // 选择排序测试
    // ArrayList *selectionSortArrayList = initArrayList(10);
    // for (int i = 0; i < 10; i++) {
    //     add(selectionSortArrayList, inttie[i]);
    // }
    // printf("选择排序测试: \n");
    // selectionSort(selectionSortArrayList);
    // destroyArrayList(selectionSortArrayList);
    //
    // // 插入排序测试
    // ArrayList *insertionSortArrayList = initArrayList(10);
    // for (int i = 0; i < 10; i++) {
    //     add(insertionSortArrayList, inttie[i]);
    // }
    // printf("插入排序测试: \n");
    // insertionSort(insertionSortArrayList);
    // destroyArrayList(insertionSortArrayList);
    //
    // // 冒泡排序测试
    // ArrayList *bubbleSortArrayListNo = initArrayList(10);
    // for (int i = 0; i < 10; i++) {
    //     add(bubbleSortArrayListNo, i);
    // }
    // printf("冒泡排序测试: \n");
    // bubbleSort(bubbleSortArrayListNo);
    // destroyArrayList(bubbleSortArrayListNo);
    //
    // // 快速排序测试
    // ArrayList *quickSortArrayList = initArrayList(10);
    // for (int i = 0; i < 10; i++) {
    //     add(quickSortArrayList, inttie[i]);
    // }
    // printf("快速排序测试: \n");
    // quickSort(quickSortArrayList, 0, quickSortArrayList->index - 1);
    // printArrayList(quickSortArrayList);
    // destroyArrayList(quickSortArrayList);

    // int arr20000[ARRAY_SIZE];
    // srand(time(NULL));
    // for (int i = 0; i < ARRAY_SIZE; i++) {
    //     arr20000[i] = rand();
    // }
    // ArrayList *quickSortArrayList20000 = initArrayList(ARRAY_SIZE);
    // for (int i = 0; i < ARRAY_SIZE; i++) {
    //     add(quickSortArrayList20000, arr20000[i]);
    // }
    // printf("快速排序测试(2,00,00): \n");
    // quickSort(quickSortArrayList20000, 0, quickSortArrayList20000->index - 1);
    // printArrayList(quickSortArrayList20000);
    // destroyArrayList(quickSortArrayList20000);

    // 归并排序测试
    // ArrayList *mergeSortArrayList = initArrayList(ARRAY_SIZE);
    // for (int i = 0; i < ARRAY_SIZE; i++) {
    //     add(mergeSortArrayList, arr20000[i]);
    // }
    // int smallArr[] = {2, 1};
    // for (int i = 0; i < 2; i++) {
    //     add(mergeSortArrayList, smallArr[i]);
    // }
    // printf("归并排序测试: \n");
    // mergeSort(mergeSortArrayList);
    // destroyArrayList(mergeSortArrayList);
    //
    // // 链表测试
    // LinkedListNode *head = createLinkedList(0);
    // for (int i = 1; i < 10; i++) {
    //     insertLinkedList(head, i);
    // }
    // for (int i = 1; i < 10; i++) {
    //     insertLinkedList(head, 5);
    // }
    // for (int i = 1; i < 10; i++) {
    //     insertLinkedList(head, 6);
    // }
    //
    // printf("链表测试 insert: \n");
    // printLinkedList(head);
    // printf("链表测试 delete: \n");
    // // deleteLinkedList(head, 3);
    // deleteLinkedList(head, 5);
    // printLinkedList(head);
    // printf("链表测试 search: \n");
    // int searchResult = searchLinkedList(head, 5);
    // printf("链表测试 search 标识符为: \n");
    // printf("%d\n", searchResult);
    // freeLinkedList(head);
    //
    // // 链表测试 归并排序(迭代)
    // LinkedListNode *head2 = createLinkedList(0);
    // int numbers[TOTAL_NUMBERS];
    // int randomNumbers[RANDOM_COUNT];
    // srand(time(NULL));
    // for (int i = 0; i < TOTAL_NUMBERS; i++) {
    //     numbers[i] = i + 1;
    // }
    // shuffle(numbers,TOTAL_NUMBERS);
    // for (int i = 0; i < RANDOM_COUNT; i++) {
    //     randomNumbers[i] = numbers[i];
    //     insertLinkedList(head2, randomNumbers[i]);
    // }
    // printf("链表测试 归并排序(迭代): \n");
    // LinkedListNode *sortedHead = mergeSortLinkedList(head2);
    // printLinkedList(sortedHead);
    // freeLinkedList(sortedHead);
    //getchar();

    //  桶排序测试
    int arr20000[ARRAY_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr20000[i] = rand();
    }
    ArrayList *bucketSortArrayList = initArrayList(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        add(bucketSortArrayList, arr20000[i]);
    }
    printf("筒排序测试: \n");
    bucketSort(bucketSortArrayList);
    destroyArrayList(bucketSortArrayList);

    return 0;
}


