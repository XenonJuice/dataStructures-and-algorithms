//
// Created by user on 2024/8/22.
//

#include "AVL_TREE.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/*only used in this file*/
static AVL_TreeNode *getMAX(AVL_TreeNode *root);

static AVL_TreeNode *getMIN(AVL_TreeNode *root);

void bfs(AVL_TreeNode *root);

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
    int rightChildTreeHeight = getHeight(node->right);
    node->height = (leftChildTreeHeight >= rightChildTreeHeight) ? leftChildTreeHeight + 1 : rightChildTreeHeight + 1;
    printf("更新节点高度: 当前节点为:%d,节点高度为:%d\n", node->val, node->height);
}

// 获取平衡因子
int getBalanceFactor(AVL_TreeNode *node) {
    if (node == NULL) {
        printf("获取平衡因子：当前节点为空\n");
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

// 插入节点
AVL_TreeNode *insert(AVL_TreeNode *root, int val) {
    // 节点为NULL时，直接返回插入的节点
    if (root == NULL) {
        return createNode(val);
    }
    // 递归直到一个为NULL的插入位置
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    } else {
        printf("已存在重复值：%d，插入失败\n", val);
        return root;
    }
    updateHeight(root);
    root = rotate(root);
    return root;
}

// 删除节点
AVL_TreeNode *delete(AVL_TreeNode *root, int val) {
    if (root == NULL) {
        printf("删除：根节点为空！\n");
        return NULL;
    }
    if (val < root->val) {
        root = delete(root->left, val);
    } else if (val > root->val) {
        root = delete(root->right, val);
        // find the target value
    } else {
        // 如果该节点包含左右两个子树
        if (root->left && root->right) {
            // 若左子树高度大于右子树高度，则将该节点替换为左子树中的最大节点
            if (getHeight(root->left) > getHeight(root->right)) {
                AVL_TreeNode *max = getMAX(root->left);
                root->val = max->val;
                root->left = delete(root->left, max->val);
                // 反之亦然
            } else {
                AVL_TreeNode *min = getMIN(root->right);
                root->val = min->val;
                root->right = delete(root->right, min->val);
            }
        }
        // 若包含一个节点，则直接将该节点替换为该节点的子节点。此处也可处理不包含节点的情况
        if (root->left == NULL || root->right == NULL) {
            AVL_TreeNode *tmp = root;
            root = root->left == NULL ? root->right : root->right;
            free(tmp);
        }
    }
    if (root == NULL) {
        printf("删除节点：树已被清空！\n");
        return root;
    }
    updateHeight(root);
    root = rotate(root);
    return root;
}

// 获取最大节点
static AVL_TreeNode *getMAX(AVL_TreeNode *root) {
    if (root == NULL) {
        printf("树为空，无法获取最大节点。\n");
        return NULL;
    }
    // 循环查找右子树中的最右侧节点
    while (root->right != NULL) {
        root = root->right;
    }
    printf("获取最大节点: 最大节点为: %d\n", root->val);
    return root;
}

// 获取最小节点
static AVL_TreeNode *getMIN(AVL_TreeNode *root) {
    if (root == NULL) {
        printf("树为空，无法获取最大节点。\n");
        return NULL;
    }
    // 循环查找左子树中的最左侧节点
    while (root->left != NULL) {
        root = root->left;
    }
    printf("获取最小节点: 最小节点为: %d\n", root->val);
    return root;
}


// 左旋
AVL_TreeNode *rotateLeft(AVL_TreeNode *node) {
    AVL_TreeNode *child = NULL, *grandChild = NULL;
    child = node->right;
    grandChild = child->left;
    child->left = node;
    node->right = grandChild;
    // 更新两个被重新连接的节点的高度 ：  nodePtr childPtr
    updateHeight(node);
    updateHeight(child);
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
    // 更新两个被重新连接的节点的高度 ：nodePtr childPtr
    updateHeight(node);
    updateHeight(child);

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
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // 右偏树
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // 无需旋转
    return node;
}

// @brief bfs
void bfs(AVL_TreeNode *root) {
    if (root == NULL) {
        printf("bfs:树为空，无法打印！\n");
        return;
    }
    printf("bfs结果: \n");
    Queue *queue = createQueue();
    enQueue(queue, root);

    while (!isEmptyQueue(queue)) {
        AVL_TreeNode *tmp = deQueue(queue);

        // 打印当前节点和它的左右子节点，检查 NULL
        if (tmp->left == NULL && tmp->right != NULL) {
            printf("节点: %d, 左子节点为:NULL , 右子节点为:%d ,\n",
                   tmp->val, tmp->right->val);
        } else if (tmp->right == NULL && tmp->left != NULL) {
            printf("节点: %d, 左子节点为:%d , 右子节点为:NULL ,\n",
                   tmp->val, tmp->left->val);
        } else if (tmp->left != NULL && tmp->right != NULL) {
            printf("节点: %d, 左子节点为:%d , 右子节点为:%d ,\n",
                   tmp->val, tmp->left->val, tmp->right->val);
        } else {
            printf("节点: %d, 左子节点为:NULL , 右子节点为:NULL ,\n",
                   tmp->val);
        }

        // 把左右子节点加入队列
        if (tmp->left != NULL) {
            enQueue(queue, tmp->left);
        }
        if (tmp->right != NULL) {
            enQueue(queue, tmp->right);
        }
    }
    destroyQueue(queue);
}

// @brief 销毁AVL树
void destroyAVLTree(AVL_TreeNode *root) {
    if (root == NULL) {
        printf("销毁AVL树：树为空，无法销毁！\n");
        return;
    }
    if (root->left != NULL) {
        destroyAVLTree(root->left);
    }
    if (root->right != NULL) {
        destroyAVLTree(root->right);
    }
    printf("销毁AVL树:销毁节点: %d\n", root->val);
    free(root);
}


// 打印二叉树（以根节点作为入口）
void printTree(AVL_TreeNode *root, int space) {
    if (root == NULL)
        return;

    // 增加间隔，表示树的层级
    space += 15;

    // 先打印右子树
    printTree(root->right, space);

    // 打印当前节点
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);

    // 打印左子树
    printTree(root->left, space);
}
