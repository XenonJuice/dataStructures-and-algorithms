//
// Created by user on 2024/8/22.
//

#ifndef AVL_TREE_H
#define AVL_TREE_H
typedef struct AVL_TreeNode AVL_TreeNode;

typedef struct AVL_TreeNode {
    int val;
    // 当前节点的高度
    int height;
    AVL_TreeNode *left;
    AVL_TreeNode *right;
} AVL_TreeNode;

// 创建节点
AVL_TreeNode *createNode(int val);

// 插入节点
AVL_TreeNode *insert(AVL_TreeNode *root, int val);

// 删除节点
AVL_TreeNode *delete(AVL_TreeNode *root, int val);

// 查找节点
AVL_TreeNode *find(AVL_TreeNode *root, int val);

// 获取节点的高度
int getHeight(AVL_TreeNode *node);

// 更新节点的高度
void updateHeight(AVL_TreeNode *node);

// 获取平衡因子
int getBalanceFactor(AVL_TreeNode *node);

// 左旋
AVL_TreeNode *rotateLeft(AVL_TreeNode *node);

// 右旋
AVL_TreeNode *rotateRight(AVL_TreeNode *node);

// 旋转
AVL_TreeNode *rotate(AVL_TreeNode *node);

// bfs 打印二叉树
void bfs(AVL_TreeNode *root);

// 深度优先遍历
void preOrder(AVL_TreeNode *root);

void inOrder(AVL_TreeNode *root);

void postOrder(AVL_TreeNode *root);

// 销毁二叉树
void destroyAVLTree(AVL_TreeNode *root);

// 打印二叉树
void printTree(AVL_TreeNode *root, int space);
#endif //AVL_TREE_H
