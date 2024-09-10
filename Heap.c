//
// Created by user on 2024/9/6.
//

#include "Heap.h"

#include <stdio.h>
#include <stdlib.h>

/*only used in this file*/
int getParentIndex(int index);

int getLeftChildIndex(int index);

int getRightChildIndex(int index);

void swapNode(Heap *heap, int one, int two);


// 创建堆
Heap *heap_create(int capacity) {
    Heap *heap = malloc(sizeof(Heap));
    if (heap == NULL) {
        printf("堆创建: 堆内存分配失败\n");
        return NULL;
    }
    heap->array = initArrayList(capacity);
    return heap;
}

// 初始堆化
Heap *heap_init(Heap *heap) {
    // 从最后一个非叶子节点开始堆化，因为从最后一个非叶子节点开始堆化，可以保证所有节点都已经堆化完成
    for (int i = getParentIndex(heap->array->index); i >= 0; i--) {
        sift_down(heap, i);
    }
    return heap;
}

// 堆销毁
void heap_destroy(Heap *heap) {
    if (heap == NULL) {
        printf("堆销毁: 堆为空\n");
        return;
    }
    // 销毁内部的 ArrayList 数据
    if (heap->array != NULL) {
        if (heap->array->data != NULL) {
            free(heap->array->data);
            printf("堆销毁: arrayList销毁\n");
        }
        free(heap->array);
        printf("堆销毁: arrayList指针销毁\n");
    }

    // 销毁堆结构体
    free(heap);
}


// 堆插入
void heap_insert(Heap *heap, int data) {
    add(heap->array, data);
    printf("堆插入:插入节点: 值为%d\n", data);
    // printf("堆插入:插入节点: 下标为%d\n", heap->array->index - 1);
    /*插入节点时，需要从末尾节点开始向上堆化*/
    sift_up(heap, heap->array->index - 1);
}

// 堆删除
int heap_delete(Heap *heap) {
    int data = heap->array->data[0];
    set(heap->array, 0, heap->array->data[heap->array->index - 1]);
    heap->array->index--;
    printf("堆删除:删除节点: 值为%d\n", data);
    /*删除头部节点时，交换头节点和尾节点的位置，所以需要从头部开始向下堆化*/
    sift_down(heap, 0);
    return data;
}

// 向上堆化
void sift_up(Heap *heap, int index) {
    while (index > 0) {
        int parentIndex = getParentIndex(index);
        // 如果父节点越界，或者当前节点比父节点小，则停止堆化
        if (heap->array->data[index] > heap->array->data[parentIndex]) {
            break;
        }
        swapNode(heap, index, parentIndex);
        index = parentIndex;
    }
}

// 向下堆化
void sift_down(Heap *heap, int index) {
    while (1) {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int min = index;
        // 如果左子节点不越界，并且左子节点比当前节点小，则将左子节点作为最小节点
        if (leftChildIndex < heap->array->index
            && heap->array->data[min] > heap->array->data[leftChildIndex]) {
            min = leftChildIndex;
        }
        /*
         * 注意这里的 heap->array->data[min] ，位置必须为min而不是index，因为左子节点与当前节点比较之后，最小节点的基准
         * 可能发生了变化，如果继续使用index会导致错误的比较，因为当前节点已经不是最小节点了，反而回到了当前节点的位置
         * 这个问题于2024年9月10日困扰了我一整个下午，进行三者比较时一定要注意基准量的变化
         */
        // 如果右子节点不越界，并且右子节点比当前节点小，则将右子节点作为最小节点
        if (rightChildIndex < heap->array->index
            && heap->array->data[min] > heap->array->data[rightChildIndex]) {
            min = rightChildIndex;
        }
        // 如果最小节点就是当前节点，则停止堆化
        if (min == index) {
            break;
        }
        swapNode(heap, index, min);
        index = min;
    }
}

// 获取堆顶元素
int heap_peek(Heap *heap) {
    return heap->array->data[0];
}

//打印堆
void heap_print(Heap *heap) {
    ArrayList *array = heap->array;
    printf("打印堆: \n");
    printArrayList(array);
}

int getParentIndex(int index) {
    return (index - 1) / 2;
}

int getLeftChildIndex(int index) {
    return index * 2 + 1;
}

int getRightChildIndex(int index) {
    return index * 2 + 2;
}

void swapNode(Heap *heap, int one, int two) {
    ArrayList *array = heap->array;
    int tmp = array->data[one];
    array->data[one] = array->data[two];
    array->data[two] = tmp;
}
