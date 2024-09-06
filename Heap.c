//
// Created by user on 2024/9/6.
//

#include "Heap.h"

#include <stdlib.h>

/*only used in this file*/
int getParentIndex(int index);

int getLeftChildIndex(int index);

int getRightChildIndex(int index);

void swapNode(Heap *heap, int one, int two);


// 创建堆
Heap *heap_create(int capacity) {
    Heap *heap = malloc(sizeof(Heap));
    heap->array->data = (int *) malloc(sizeof(int) * capacity);
    heap->array->capacity = capacity;
    heap->array->index = 0;
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

// 销毁堆
void heap_destroy(Heap *heap) {
    free(heap->array->data);
    free(heap);
}

// 堆插入
void heap_insert(Heap *heap, int data) {
    heap->array->data[heap->array->index] = data;
    heap->array->index++;
    /*插入节点时，需要从末尾节点开始向上堆化*/
    sift_up(heap, heap->array->index);
}

// 堆删除
int heap_delete(Heap *heap) {
    int data = heap->array->data[0];
    heap->array->data[0] = heap->array->data[heap->array->index];
    heap->array->index--;
    /*删除头部节点时，末尾节点的值赋予了头部节点的位置，所以需要从头部开始向下堆化*/
    sift_down(heap, 0);
    return data;
}

// 向上堆化
void sift_up(Heap *heap, int index) {
    while (1) {
        int parentIndex = getParentIndex(index);
        // 如果父节点越界，或者当前节点比父节点小，则停止堆化
        if (parentIndex < 0 || heap->array->data[index] < heap->array->data[parentIndex]) {
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
        // 如果左子节点不越界，或者左子节点比当前节点小，则将左子节点作为最小节点
        if (leftChildIndex <= heap->array->index
            && heap->array->data[index] > heap->array->data[leftChildIndex]) {
            min = leftChildIndex;
        }
        // 如果右子节点不越界，并且右子节点比当前节点小，则将右子节点作为最小节点
        if (rightChildIndex <= heap->array->index
            && heap->array->data[index] > heap->array->data[rightChildIndex]) {
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
