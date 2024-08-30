//
// Created by user on 2024/8/30.
//

#ifndef QUEUE_H
#define QUEUE_H
#include "AVL_TREE.h"

typedef struct QueueNode {
 void *node;
 struct QueueNode *next;
} QueueNode;

typedef struct Queue {
 QueueNode *front;
 QueueNode *rear;
} Queue;

// 创建队列
Queue *createQueue();

// 入队
void enQueue(Queue *queue, AVL_TreeNode *node);

// 出队
AVL_TreeNode *deQueue(Queue *queue);

// 判断队列是否为空
int isEmptyQueue(Queue *queue);

// 销毁队列
void destroyQueue(Queue *queue);
#endif //QUEUE_H
