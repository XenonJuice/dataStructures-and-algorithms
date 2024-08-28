//
// Created by user on 2024/8/22.
//

#include "AVL_TREE.h"
#include <stdio.h>
#include <stdlib.h>
// 创建一个节点
AVL_TreeNode *createNode(int val) {
    AVL_TreeNode *newNode = malloc(sizeof(AVL_TreeNode));
    if (newNode == NULL) {
        printf("创建节点失败: 内存分配失败\n");
        return NULL;
    }

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

// 获取节点的高度
int getHeight(AVL_TreeNode *node) {
    // 如果节点为空，则高度为-1
    return node == NULL ? -1 : node->height;
}

// 更新节点的高度
void updateHeight(AVL_TreeNode *node) {
    if (node == NULL) {
        printf("更新节点高度: 当前节点为空\n");
        return;
    }
    /*若当前节点的左子树的高度>=右子树的高度，则当前节点的高度为左子树高度+1；反之亦然*/
    int leftChildTreeHeight = getHeight(node->left);
    int rightChildTreeHeight = getHeight(node->left);
    if (leftChildTreeHeight >= rightChildTreeHeight) node->height = leftChildTreeHeight + 1;
    if (leftChildTreeHeight < rightChildTreeHeight) node->height = rightChildTreeHeight + 1;
    printf("更新节点高度: 当前节点为:%d\n", node->height);
}

// 获取平衡因子
int getBalanceFactor(AVL_TreeNode *node) {
    if (node == NULL) {
        printf("获取平衡因子：当前节点为空");
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// 查找节点
AVL_TreeNode *find(AVL_TreeNode *root, int val) {
    if (root == NULL) {
        printf("查找节点: 当前树为空\n");
        return NULL;
    }
    AVL_TreeNode *tmp = root;
    while (tmp != NULL) {
        if (tmp->val > val) {
            tmp = tmp->left;
        } else if (tmp->val < val) {
            tmp = tmp->right;
        } else {
            return tmp;
        }
    }
    printf("查找节点: 未找到节点\n");
    return NULL;
}


/* 尝试使用迭代来实现对AVL树的插入，但是似乎不太现实。
 * 考虑到用栈来记录每一个遍历过的节点，但是中间发生旋转，栈中存储的节点关系会发生变化，并不可行
 * 考虑到用栈来记录每一个遍历过的节点，当从底部第一个节点发生旋转时，从根节点重新遍历到当前节点入栈，时间复杂度过高，不可行。
// 插入节点
AVL_TreeNode *insert(AVL_TreeNode *root, int val) {
    if (root == NULL) {
        // 如果根节点为空，则创建一个新的节点;
        AVL_TreeNode *newRootNode = createNode(val);
        return newRootNode;
    }
    AVL_TreeNode *cur = root;
    /*
     * 这里如果将pre声明为NULL，
     * ide会一直提示警告信息，
     * 但是我不想看到警告信息
     #1#
    // AVL_TreeNode *pre = NULL;
    AVL_TreeNode *pre = root;
    while (cur != NULL) {
        pre = cur;
        if (cur->val == val) {
            printf("插入节点: 节点已存在\n");
            return cur;
        }
        // 如果当前节点的值大于val，则向左子树查找插入位置，反之亦然
        if (cur->val > val) cur = cur->left;
        if (cur->val < val) cur = cur->right;
    }
    // 向左或者右层层递进，直到找到一个空节点
    // 如果当前节点的值大于val，则向左子树插入，反之亦然
    AVL_TreeNode *newNode = createNode(val);
    if (pre->val < val) pre->right = newNode;
    if (pre->val > val) pre->left = newNode;
    return newNode;
}
*/

// 左旋
AVL_TreeNode *rotateLeft(AVL_TreeNode *node) {
    AVL_TreeNode *child = NULL, *grandChild = NULL;
    child = node->right;
    grandChild = child->left;
    child->left = node;
    node->right = grandChild;
    // 更新两个被重新连接的节点的高度 ： childPtr nodePtr
    updateHeight(child);
    updateHeight(node);
    // 返回的是重新成为子树根节点的child节点
    return child;
}

// 右旋
AVL_TreeNode *rotateRight(AVL_TreeNode *node) {
    AVL_TreeNode *child = NULL, *grandChild = NULL;
    child = node->left;
    grandChild = child->right;
    child->right = node;
    node->left = grandChild;
    // 更新两个被重新连接的节点的高度 ： childPtr nodePtr
    updateHeight(child);
    updateHeight(node);
    // 返回的是重新成为子树根节点的child节点
    return child;
}


/*
 * 失衡节点的平衡因子         子节点的平衡因子          旋转方法
 * ----------------------------------------------------------------
 * > 1 （左偏树）               >= 0                右旋
 * > 1 （左偏树）               < 0               左旋 & 右旋
 * < -1 （右偏树）              <= 0                左旋
 * < -1 （右偏树）              > 0               右旋 &左旋
 */
// 旋转
AVL_TreeNode *rotate(AVL_TreeNode *node) {
    int balanceFactor = getBalanceFactor(node);
    // 左偏树
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }
        node->left = rotateLeft(node);
        return rotateRight(node);
    }
    // 右偏树
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }
        node->right = rotateRight(node);
        return rotateLeft(node);
    }

    // 无需旋转
    return node;
}
