<div align="center">

[![English](https://img.shields.io/badge/Language-English-blue?style=for-the-badge)](README.md)
[![简体中文](https://img.shields.io/badge/语言-简体中文-red?style=for-the-badge)](README.zh-CN.md)
[![日本語](https://img.shields.io/badge/言語-日本語-green?style=for-the-badge)](README.ja.md)

</div>

# 数据结构与算法 (Data Structures and Algorithms)

一个使用 C 语言实现的数据结构和算法学习项目，包含了常见的数据结构和经典算法的实现。

## 📚 实现的数据结构

### 1. AVL 树 (AVL Tree)
- 自平衡二叉搜索树
- 支持插入、删除、查找操作
- 包含前序、中序、后序和层序遍历
- 提供树的可视化打印功能

### 2. 动态数组 (ArrayList)
- 可动态扩展和收缩的数组
- 支持基本的增删改查操作
- 集成了多种排序算法
- 支持二分查找

### 3. 双向链表 (Doubly Linked List)
- 带前驱和后继指针的链表
- 每个节点有唯一标识符
- 支持归并排序

### 4. 栈 (Stack)
- 基于链表实现
- 支持 push、pop、peek 操作
- 用于树的遍历

### 5. 队列 (Queue)
- 基于链表实现
- 支持入队、出队操作
- 用于树的层序遍历

### 6. 堆 (Heap)
- 基于数组实现的二叉堆
- 支持堆化操作
- 可用于优先队列和 TopK 问题

## 🔧 实现的算法

### 排序算法
| 算法 | 时间复杂度 (平均) | 空间复杂度 | 稳定性 |
|------|------------------|-----------|--------|
| 冒泡排序 | O(n²) | O(1) | 稳定 |
| 选择排序 | O(n²) | O(1) | 不稳定 |
| 插入排序 | O(n²) | O(1) | 稳定 |
| 归并排序 | O(n log n) | O(n) | 稳定 |
| 快速排序 | O(n log n) | O(log n) | 不稳定 |
| 桶排序 | O(n + k) | O(n + k) | 稳定 |
| 计数排序 | O(n + k) | O(k) | 稳定 |
| 基数排序 | O(d × n) | O(n + k) | 稳定 |

### 搜索算法
- **二分查找**: 在有序数组中查找元素，时间复杂度 O(log n)
- **深度优先搜索 (DFS)**: 用于树的遍历
- **广度优先搜索 (BFS)**: 用于树的层序遍历

### 其他算法
- **Fisher-Yates 洗牌算法**: 随机打乱数组
- **TopK 算法**: 使用堆查找最大的 K 个元素

## 🛠️ 编译和运行

### 环境要求
- C 编译器 (支持 C23 标准)
- CMake 3.30 或更高版本

### 编译步骤

#### 方法1：使用 CMake（推荐）
```bash
# 创建构建目录
mkdir build
cd build

# 生成构建文件
cmake ..

# 编译项目
make

# 运行程序
./dataStructures-and-algorithms
```

#### 方法2：直接使用 GCC
```bash
# 编译所有源文件
gcc -std=c23 -Wall -Wextra -Werror -c STACK.c Depth-First-Search.c AVL_TREE.c Queue.c ArrayList.c LinkedList.c Heap.c

# 链接生成可执行文件
gcc -std=c23 -Wall -Wextra -Werror main.c STACK.o Depth-First-Search.o AVL_TREE.o Queue.o ArrayList.o LinkedList.o Heap.o -lm -o dataStructures-and-algorithms

# 运行程序
./dataStructures-and-algorithms
```

## 📁 项目结构
```
.
├── CMakeLists.txt          # CMake 配置文件
├── main.c                  # 主程序和测试代码
├── AVL_TREE.h/c           # AVL 树实现
├── ArrayList.h/c          # 动态数组实现
├── LinkedList.h/c         # 双向链表实现
├── STACK.h/c              # 栈实现
├── Queue.h/c              # 队列实现
├── Heap.h/c               # 堆实现
└── Depth-First-Search.h/c # DFS 算法实现
```

## 📝 使用示例

### 创建和使用动态数组
```c
// 初始化容量为 10 的数组
ArrayList *list = initArrayList(10);

// 添加元素
add(list, 5);
add(list, 3);
add(list, 8);

// 排序
quickSort(list, 0, list->index - 1);

// 打印结果
printArrayList(list);

// 释放内存
destroyArrayList(list);
```

### 创建和使用 AVL 树
```c
// 创建空树
AVL_TreeNode *root = NULL;

// 插入元素
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 15);

// 中序遍历
inOrder(root);

// 释放内存
destroyAVLTree(root);
```

## 🧪 测试

main.c 文件包含了所有数据结构和算法的测试代码。你可以取消注释相应的测试部分来运行特定的测试。

## 📄 许可证

本项目仅供学习和教育目的使用。

## 🤝 贡献

欢迎提交 Issue 和 Pull Request 来改进代码或添加新的数据结构和算法。

## 📚 参考资料

- 《算法导论》(Introduction to Algorithms)
- 《数据结构与算法分析》(Data Structures and Algorithm Analysis)