//
// Created by user on 2024/9/6.
//

#ifndef HEAP_H
#define HEAP_H
#include "ArrayList.h"

typedef struct Heap {
    ArrayList *array;
} Heap;

// 初始堆化
Heap *heap_init(Heap *heap);

// 创建堆
Heap *heap_create(int capacity);

// 销毁堆
void heap_destroy(Heap *heap);

// 堆插入
void heap_insert(Heap *heap, int data);

// 堆删除
int heap_delete(Heap *heap);

// 向上堆化
void sift_up(Heap *heap, int index);

// 向下堆化
void sift_down(Heap *heap, int index);

//打印堆
void heap_print(Heap *heap);

#endif //HEAP_H
