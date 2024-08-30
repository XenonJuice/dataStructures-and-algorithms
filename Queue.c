//
// Created by user on 2024/8/30.
//
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

// @brief 创建一个队列
Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("队列内存分配失败：malloc error");
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// @brief 入队
void enQueue(Queue *queue, AVL_TreeNode *node) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("入隊内存分配失败：malloc error");
        return;
    }
    newNode->node = node;
    newNode->next = NULL;
    if (isEmptyQueue(queue)) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// @brief 出队
AVL_TreeNode *deQueue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        printf("出队：队列为空\n");
        return NULL;
    }
    QueueNode *tmp = queue->front;
    AVL_TreeNode *node = tmp->node;
    queue->front = queue->front->next;
    if (isEmptyQueue(queue)) {
        queue->rear = NULL;
    }
    free(tmp);
    return node;
}

// @brief 检查队列是否为空
int isEmptyQueue(Queue *queue) {
    return queue->front == NULL;
}

// @brief 销毁队列
void destoryQueue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        printf("销毁队列:队列为空，无需销毁\n");
        return;
    }
    while (!isEmptyQueue(queue)) {
        deQueue(queue);
    }
    free(queue);
}
