//
// Created by user on 2024/9/20.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode linkedListNode;

typedef struct LinkedListNode {
    int val;
    int specificID;
    struct LinkedListNode *prev;
    struct LinkedListNode *next;
} LinkedListNode;

// 创建链表
LinkedListNode *createLinkedList(int val);

// 插入节点
LinkedListNode *insertLinkedList(LinkedListNode *head, int val);

// 删除节点
LinkedListNode *deleteLinkedList(LinkedListNode *head, int val);

// 查找节点
int searchLinkedList(LinkedListNode *head, int val);

// 打印链表
void printLinkedList(LinkedListNode *head);

// 获取链表长度
int getLinkedListLength(LinkedListNode *head);

// 归并排序（迭代）
LinkedListNode *mergeSortLinkedList(LinkedListNode *head);

// 释放链表
void freeLinkedList(LinkedListNode *head);


#endif //LINKEDLIST_H
