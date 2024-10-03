//
// Created by user on 2024/9/5.
//

#include "ArrayList.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*only used in this file*/
static ArrayList *expandArrayList(ArrayList *array);

static ArrayList *shrinkArrayList(ArrayList *list);

static void merge(int *arr, int left, int mid, int right);

// 基数排序具体实现
static void radixSortImp(ArrayList *list, int exp);

// 获取数据特定位上的值
static int getDigit(int num, int exp);


// 初始化一个ArrayList，返回一个ArrayList指针
ArrayList *initArrayList(int capacity) {
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL) {
        printf("初始化ArrayList：ArrayList内存分配失败\n");
        return NULL;
    }
    list->data = malloc(sizeof(int) * capacity);
    if (list->data == NULL) {
        printf("初始化ArrayList：array内存分配失败\n");
        free(list);
        return NULL;
    }
    list->capacity = capacity;
    list->index = 0;
    return list;
}

// 向ArrayList中添加一个元素
void add(ArrayList *list, int value) {
    if (list == NULL) {
        printf("添加元素：ArrayList为空\n");
        return;
    }
    if (list->index == list->capacity) {
        list = expandArrayList(list);
    }
    int *dataPtr = list->data;
    int index = list->index;
    *(dataPtr + index) = value;
    list->index++;
    // printf("添加元素：%d 到ArrayList中，下标为：%d \n", value, index);
}

// 删除ArrayList中指定位置的元素
void removeFromArrayList(ArrayList *list, int index) {
    if (list == NULL) {
        printf("删除元素：ArrayList为空\n");
        return;
    }
    if (!checkRange(list, index)) {
        printf("删除元素：索引不合法\n");
        return;
    }
    int *dataPtr = list->data;
    int arrayIndex = list->index;
    for (int i = index + 1; i < arrayIndex; i++) {
        *(dataPtr + i - 1) = *(dataPtr + i);
    }
    list->index--;
    shrinkArrayList(list);
}

// 获取ArrayList中指定位置的元素
int get(ArrayList *list, int index) {
    return *(list->data + index);
}

// 设置ArrayList中指定位置的元素
void set(ArrayList *list, int index, int value) {
    if (list == NULL) {
        printf("设置元素：ArrayList为空\n");
        return;
    }
    if (!checkRange(list, index)) {
        printf("设置元素：索引不合法\n");
        return;
    }
    int *dataPtr = list->data;
    int tmpVal = *(dataPtr + index);
    dataPtr[index] = value;
    printf("设置元素：%d 到ArrayList中，替换了原值:%d\n", value, tmpVal);
}

// 获取ArrayList中指定元素的索引
int indexOf(ArrayList *list, int value) {
    if (list == NULL) {
        printf("获取元素索引：ArrayList为空\n");
        return -1;
    }
    int *dataPtr = list->data;
    int arrayIndex = list->index;
    for (int i = 0; i < arrayIndex; i++) {
        if (*(dataPtr + i) == value) {
            printf("获取元素索引：指定元素：%d 的索引为：…%d\n", value, i);
            return i;
        }
    }
    printf("获取元素索引：未找到元素\n");
    return -1;
}

// 清空整个ArrayList
void clearArrayList(ArrayList *list) {
    if (list->data != NULL) {
        free(list->data);
    }
    list->data = malloc(sizeof(int) * list->capacity);
    list->index = 0;
    printf("清空ArrayList：ArrayList已清空\n");
}

// 销毁ArrayList
void destroyArrayList(ArrayList *list) {
    free(list->data);
    free(list);
    printf("销毁ArrayList：ArrayList已销毁\n");
}

// 打印ArrayList中的所有元素
void printArrayList(const ArrayList *list) {
    printf("打印ArrayList：ArrayList中的所有元素为：\n");
    for (int i = 0; i < list->index; i++) {
        printf("%d ", *(list->data + i));
    }
    printf("\n");
}

// 获取ArrayList的长度
int getLength(ArrayList *list) {
    return list->index; //+ 1;
}

// 获取ArrayList的容量
int getCapacity(ArrayList *list) {
    return list->capacity;
}


// 检查ArrayList的索引是否合法
int checkRange(ArrayList *list, int index) {
    return index >= 0 && index <= list->index;
}

// 获取最大值
int getMax(ArrayList *list) {
    int *dataPtr = list->data;
    int arrayIndex = list->index;
    int max = *dataPtr;
    for (int i = 1; i < arrayIndex; i++) {
        if (*(dataPtr + i) > max) {
            max = *(dataPtr + i);
        }
    }
    return max;
}

// 获取最小值
int getMin(ArrayList *list) {
    int *dataPtr = list->data;
    int arrayIndex = list->index;
    int min = *dataPtr;
    for (int i = 1; i < arrayIndex; i++) {
        if (*(dataPtr + i) < min) {
            min = *(dataPtr + i);
        }
    }
    return min;
}

// 扩容
static ArrayList *expandArrayList(ArrayList *list) {
    int newCapacity = (list->capacity) << 1;
    int *newDataPtr = realloc(list->data, sizeof(int) * newCapacity);
    if (newDataPtr == NULL) {
        printf("扩容ArrayList：新Array内存分配失败\n");
        return NULL;
    }
    list->data = newDataPtr;
    list->capacity = newCapacity;
    printf("扩容ArrayList：扩容结束，扩展后的容量为 %d\n", list->capacity);
    return list;
}

// 收缩
static ArrayList *shrinkArrayList(ArrayList *list) {
    if (getLength(list) < list->capacity / 2) {
        int newCapacity = (list->capacity) >> 1;
        int *newDataPtr = realloc(list->data, sizeof(int) * newCapacity);
        if (newDataPtr == NULL) {
            printf("收缩ArrayList：新Array内存分配失败\n");
            return NULL;
        }
        list->data = newDataPtr;
        list->capacity = newCapacity;
    }
    printf("收缩ArrayList：收缩结束，收缩后的容量为 %d\n", list->capacity);
    return list;
}


// Fisher-Yates
void shuffle(int *arr, int n) {
    if (arr == NULL) {
        printf("洗牌：数组为空\n");
        return;
    }
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = tmp;
    }
    printf("洗牌：已打乱\n");
}

// 二分查找
int binarySearch(ArrayList *list, int target) {
    int left = 0;
    int right = list->index - 1;
    int *arr = list->data;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// 冒泡排序
void bubbleSort(ArrayList *list) {
    int *arr = list->data;
    int n = list->index;
    int flag;
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
        }
        if (!flag) {
            printf("冒泡排序：数组已有序，无需继续\n");
            break;
        }
    }
    printf("冒泡排序：已排序\n");
    printArrayList(list);
}

// 选择排序
void selectionSort(ArrayList *list) {
    int *arr = list->data;
    int n = list->index;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (*(arr + minIndex) > *(arr + j)) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int tmp = *(arr + i);
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    printf("选择排序：已排序\n");
    printArrayList(list);
}

// 插入排序
void insertionSort(ArrayList *list) {
    int *arr = list->data;
    int n = list->index;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int tmp = arr[i];
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
    printf("插入排序：已排序\n");
    printArrayList(list);
}

// 归并排序
void mergeSort(ArrayList *list) {
    int *arr = list->data;
    int n = list->index;
    for (int stepSize = 1; stepSize < n; stepSize <<= 1) {
        for (int left = 0; left < n - 1; left += stepSize << 1) {
            int mid = left + stepSize - 1;
            int right = left + (stepSize << 1) - 1 < n - 1 ? left + (stepSize << 1) - 1 : n - 1;
            if (mid < right) merge(arr, left, mid, right);
        }
    }
    printf("归并排序：已排序\n");
    printArrayList(list);
}

// 合并
void merge(int *arr, int left, int mid, int right) {
    int *tmp = malloc(sizeof(int) * (right - left + 1));
    /*
     * i for leftArr pointer
     * j for rightArr pointer
     * k for tmpArr pointer
     */
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    // handle attr not merged in left and right arr
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];
    // copy tmpArr back to arr
    for (i = left, k = 0; i <= right; i++, k++) arr[i] = tmp[k];
    free(tmp);
}

// 快速排序
void quickSort(ArrayList *list, int left, int right) {
    int *arr = list->data;
    while (left < right) {
        /*快速排序的结束循环的标准应该是前后指针相遇，
         *而简单通过swapFlag判断是否发生交换会导致一侧子数组有序，
         *但是另一侧子数组无序的状态下，无序子数组未能排序便提前结束的问题*/
        // int swapFlag = 0;
        int i = left, j = right;
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = arr[pivotIndex];
        arr[pivotIndex] = arr[right];
        arr[right] = pivot;
        // 分区操作
        while (i < j) {
            while (i < j && arr[i] <= pivot) i++;
            if (i < j) {
                arr[j--] = arr[i];
                //swapFlag = 1;
            }
            while (i < j && arr[j] >= pivot) j--;
            if (i < j) {
                arr[i++] = arr[j];
                // swapFlag = 1;
            }
        }
        arr[i] = pivot;
        // if (!swapFlag) {
        //     break;
        // }
        // 尾递归优化：优先递归处理较短的子数组
        if (i - left < right - i) {
            quickSort(list, left, i - 1);
            left = i + 1;
        } else {
            quickSort(list, i + 1, right);
            right = i - 1;
        }
    }
}

// 桶排序
void bucketSort(ArrayList *list) {
    int *arr = list->data;
    int n = list->index;
    // 最小值和最大值
    int min = getMin(list);
    int max = getMax(list);
    // 桶数量
    int bucketCount = sqrt(getLength(list));
    // 桶范围
    int bucketSize = (max - min + 1) / bucketCount + 1;
    // 初始化桶和元素数量指针
    int **buckets = calloc(bucketCount, sizeof(int *));
    int *bucketElements = calloc(bucketCount, sizeof(int));
    // 将元素分配到桶中
    for (int i = 0; i < n; i++) {
        // 所在桶编号
        int bucketIndex = (*(arr + i) - min) / bucketSize;
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = calloc(bucketSize, sizeof(int));
        }
        buckets[bucketIndex][bucketElements[bucketIndex]++] = *(arr + i);
    }
    // 对每个桶进行排序
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i] != NULL) {
            ArrayList *tmpArray = initArrayList(bucketElements[i]);
            for (int f = 0; f < bucketElements[i]; f++) {
                add(tmpArray, buckets[i][f]);
            }
            // 使用插入排序对每个桶进行排序
            insertionSort(tmpArray);
            // 将排序后的元素复制回原数组
            for (int f = 0; f < bucketElements[i]; f++) {
                buckets[i][f] = tmpArray->data[f];
            }
            free(tmpArray->data);
            free(tmpArray);
        }
    }
    // 合并所有桶中的元素
    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i] != NULL) {
            for (int j = 0; j < bucketElements[i]; j++) {
                arr[k++] = buckets[i][j];
            }
            free(buckets[i]);
        }
    }
    free(buckets);
    free(bucketElements);
    printf("桶排序：已排序\n");
    printArrayList(list);
}

// 计数排序
void countingSort(ArrayList *list) {
    int *arr = list->data;
    int n = list->index;
    int max = getMax(list);
    int *count = calloc(max + 1, sizeof(int));
    // count out the number of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // turn the number of each element to the prefix sum
    for (int i = 0; i < max; i++) {
        count[i + 1] += count[i];
    }
    int *res = malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; i--) {
        int num = arr[i];
        res[count[num] - 1] = num;
        count[num]--;
    }
    memcpy(arr, res, n * sizeof(int));
    printf("计数排序：已排序\n");
    printArrayList(list);
    free(count);
}

// 基数排序
void radixSort(ArrayList *list) {
    int max = getMax(list);
    for (int exp = 1; exp <= max; exp = (exp << 3) + (exp << 1)) {
        radixSortImp(list, exp);
    }
}

// 基数排序具体实现
void radixSortImp(ArrayList *list, int exp) {
    int *arr = list->data;
    int n = list->index;
    const int RADIX = 10;
    // 长度为 10 的桶数组，用于统计各数字出现次数
    int *counter = calloc(RADIX, sizeof(int));
    // 统计 0~9 各数字的出现次数
    for (int i = 0; i < n; i++) {
        // 获取 arr[i] 第 k 位，记为 d
        int d = getDigit(arr[i], exp);
        // 统计数字 d 的出现次数
        counter[d]++;
    }
    // turn the number of each element to the prefix sum
    for (int i = 1; i < RADIX; i++) {
        counter[i] += counter[i - 1];
    }
    // 倒序遍历，根据桶内统计结果，将各元素填入 res
    int *res = malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; i--) {
        // 获取当前原数组中的元素 arr[i] 的第 个十百千万 位
        int d = getDigit(arr[i], exp);
        // 获取 d 在数组中的索引 j
        int j = counter[d] - 1;
        // 将当前元素填入索引 j
        res[j] = arr[i];
        // 将 d 的数量减 1
        counter[d]--;
    }
    // 覆盖
    memcpy(arr, res, n * sizeof(int));
    printf("基数排序：\n");
    printArrayList(list);
    free(counter);
    free(res);
}

// 获取数据特定位上的值
int getDigit(int num, int exp) {
    return num / exp % 10;
}
