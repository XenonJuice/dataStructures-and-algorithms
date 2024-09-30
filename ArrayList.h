//
// Created by user on 2024/9/5.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
typedef struct ArrayList ArrayList;

typedef struct ArrayList {
    int index;
    int *data;
    int capacity;
} ArrayList;

// 初始化一个ArrayList，返回一个ArrayList指针
ArrayList *initArrayList(int capacity);

// 向ArrayList中添加一个元素
void add(ArrayList *list, int value);

// 删除ArrayList中指定位置的元素
void removeFromArrayList(ArrayList *list, int index);

// 获取ArrayList中指定位置的元素
int get(ArrayList *list, int index);

// 获取ArrayList中指定元素的索引
int indexOf(ArrayList *list, int value);

// 设置ArrayList中指定位置的元素
void set(ArrayList *list, int index, int value);

// 清空整个ArrayList
void clearArrayList(ArrayList *list);

// 销毁ArrayList
void destroyArrayList(ArrayList *list);

// 打印ArrayList中的所有元素
void printArrayList(const ArrayList *list);

// 获取ArrayList的长度
int getLength(ArrayList *list);

// 获取ArrayList的容量
int getCapacity(ArrayList *list);

// 检查ArrayList的索引是否合法
int checkRange(ArrayList *list, int index);

// Fisher-Yates
void shuffle(int *arr, int n);

// 二分查找
int binarySearch(ArrayList *list, int target);

// 冒泡排序
void bubbleSort(ArrayList *list);

// 选择排序
void selectionSort(ArrayList *list);

// 插入排序
void insertionSort(ArrayList *list);

// 归并排序
void mergeSort(ArrayList *list);

// 快速排序
void quickSort(ArrayList *list, int left, int right);

// 桶排序
void bucketSort(ArrayList *list);

#endif //ARRAYLIST_H
