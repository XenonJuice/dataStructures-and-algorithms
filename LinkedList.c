//
// Created by user on 2024/9/20.
//

#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
/*only used in this file*/
static int globalID = 0;

// 分割链表，并返回分割后的右侧链表头节点
static LinkedListNode *splitLinkedList(LinkedListNode *head, int size);

// 合并链表
static LinkedListNode *mergeLinkedList(LinkedListNode *left, LinkedListNode *right);

// 创建链表
LinkedListNode *createLinkedList(int val) {
   LinkedListNode *head = malloc(sizeof(LinkedListNode));
   if (head == NULL) {
      printf("创建链表：内存分配失败\n");
      return NULL;
   }
   head->val = val;
   head->next = NULL;
   head->prev = NULL;
   head->specificID = globalID++;
   return head;
}

// 插入节点
LinkedListNode *insertLinkedList(LinkedListNode *head, int val) {
   LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
   if (newNode == NULL) {
      printf("链表插入节点：内存分配失败\n");
      return NULL;
   }
   LinkedListNode *tmp = head;
   *newNode = (LinkedListNode){
      .val = val, .next = NULL, .prev = NULL, .specificID = globalID++
   };
   if (head == NULL) return newNode;
   while (head->next != NULL) {
      head = head->next;
   }
   head->next = newNode;
   newNode->prev = head;
   printf("链表插入节点结束：插入值为：%d\n", val);
   return tmp;
}

// 删除节点
LinkedListNode *deleteLinkedList(LinkedListNode *head, int val) {
   if (head == NULL) {
      printf("删除节点：链表为空\n");
      return NULL;
   }
   LinkedListNode *current = head;
   while (current != NULL) {
      if (current->val == val) {
         // 头节点
         if (current == head) {
            head = current->next;
            if (head != NULL) {
               head->prev = NULL;
            }
         } else {
            // 非头节点
            current->prev->next = current->next;
            // 非尾节点
            if (current->next != NULL) {
               current->next->prev = current->prev;
            }
         }
         LinkedListNode *temp = current;
         current = current->next;
         free(temp);
      } else {
         current = current->next;
      }
   }
   free(current);
   printf("删除节点结束：删除值为：%d\n", val);
   return head;
}

int searchLinkedList(LinkedListNode *head, int val) {
   if (head == NULL) {
      printf("查找节点：链表为空\n");
      return -1;
   }
   LinkedListNode *current = head;
   while (current != NULL) {
      if (current->val == val) {
         printf("查找节点结束\n");
         return current->specificID;
      }
      current = current->next;
   }
   printf("查找节点结束：未找到节点\n");
   return -1;
}

// 打印链表
void printLinkedList(LinkedListNode *head) {
   printf("打印链表：\n");
   LinkedListNode *current = head;
   while (current != NULL) {
      printf("值：%d ，标识符：%d\n", current->val, current->specificID);
      current = current->next;
   }
   printf("\n");
}

// 获取链表长度
int getLinkedListLength(LinkedListNode *head) {
   int length = 0;
   LinkedListNode *current = head;
   while (current != NULL) {
      length++;
      current = current->next;
   }
   printf("链表长度：%d\n", length);
   return length;
}

// 归并排序（迭代）
LinkedListNode *mergeSortLinkedList(LinkedListNode *head) {
   if (head == NULL) {
      printf("链表归并排序：链表为空\n");
      return NULL;
   }
   int length = getLinkedListLength(head);
   LinkedListNode *dummy = malloc(sizeof(LinkedListNode));
   dummy->next = head;
   for (int i = 1; i < length; i <<= 1) {
      LinkedListNode *current = dummy->next;
      LinkedListNode *tail = dummy;
      while (current) {
         LinkedListNode *left = current;
         LinkedListNode *right = splitLinkedList(left, i);
         current = splitLinkedList(right, i);
         tail->next = mergeLinkedList(left, right);
         while (tail->next) tail = tail->next;
      }
   }
   LinkedListNode *tmp = dummy->next;
   free(dummy);
   return tmp;
}

// 分割链表，并返回分割后的右侧链表头节点
static LinkedListNode *splitLinkedList(LinkedListNode *head, int size) {
   if (head == NULL) {
      printf("分割链表：链表为空,步长为:%d\n", size);
      return NULL;
   }
   LinkedListNode *current = head;
   LinkedListNode *prev = NULL;
   for (int i = 0; i < size && current; i++) {
      prev = current;
      current = current->next;
   }
   if (prev != NULL) prev->next = NULL;
   return current;
}

// 合并链表
static LinkedListNode *mergeLinkedList(LinkedListNode *left, LinkedListNode *right) {
   LinkedListNode *dummy = malloc(sizeof(LinkedListNode));
   LinkedListNode *tail = dummy;
   while (left && right) {
      if (left->val < right->val) {
         tail->next = left;
         left = left->next;
         tail = tail->next;
         tail->next = NULL;
      } else {
         tail->next = right;
         right = right->next;
         tail = tail->next;
         tail->next = NULL;
      }
   }
   if (left) tail->next = left;
   if (right) tail->next = right;
   LinkedListNode *tmp = dummy->next;
   free(dummy);
   return tmp;
}

// 释放链表
void freeLinkedList(LinkedListNode *head) {
   LinkedListNode *current = head;
   while (current != NULL) {
      LinkedListNode *temp = current;
      current = current->next;
      free(temp);
   }
   printf("链表已释放\n");
}
