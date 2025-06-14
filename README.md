
<div align="center">

[![English](https://img.shields.io/badge/Language-English-blue?style=for-the-badge)](README.md)
[![简体中文](https://img.shields.io/badge/语言-简体中文-red?style=for-the-badge)](README.zh-CN.md)
[![日本語](https://img.shields.io/badge/言語-日本語-green?style=for-the-badge)](README.ja.md)

</div>

# Data Structures and Algorithms

A comprehensive C implementation of common data structures and classic algorithms for learning purposes.

## 📚 Implemented Data Structures

### 1. AVL Tree
- Self-balancing binary search tree
- Supports insertion, deletion, and search operations
- Includes pre-order, in-order, post-order, and level-order traversals
- Provides tree visualization printing

### 2. ArrayList (Dynamic Array)
- Dynamically resizable array
- Supports basic CRUD operations
- Integrated with multiple sorting algorithms
- Supports binary search

### 3. Doubly Linked List
- Nodes with both previous and next pointers
- Each node has a unique identifier
- Supports merge sort

### 4. Stack
- Linked list-based implementation
- Supports push, pop, and peek operations
- Used for tree traversals

### 5. Queue
- Linked list-based implementation
- Supports enqueue and dequeue operations
- Used for tree level-order traversal

### 6. Heap
- Array-based binary heap implementation
- Supports heapify operations
- Can be used for priority queues and TopK problems

## 🔧 Implemented Algorithms

### Sorting Algorithms
| Algorithm | Time Complexity (Avg) | Space Complexity | Stability |
|-----------|---------------------|------------------|-----------|
| Bubble Sort | O(n²) | O(1) | Stable |
| Selection Sort | O(n²) | O(1) | Unstable |
| Insertion Sort | O(n²) | O(1) | Stable |
| Merge Sort | O(n log n) | O(n) | Stable |
| Quick Sort | O(n log n) | O(log n) | Unstable |
| Bucket Sort | O(n + k) | O(n + k) | Stable |
| Counting Sort | O(n + k) | O(k) | Stable |
| Radix Sort | O(d × n) | O(n + k) | Stable |

### Search Algorithms
- **Binary Search**: Search in sorted arrays with O(log n) time complexity
- **Depth-First Search (DFS)**: Used for tree traversals
- **Breadth-First Search (BFS)**: Used for tree level-order traversal

### Other Algorithms
- **Fisher-Yates Shuffle**: Randomly shuffle an array
- **TopK Algorithm**: Find the K largest elements using heap

## 🛠️ Build and Run

### Requirements
- C compiler (supporting C23 standard)
- CMake 3.30 or higher

### Build Steps

#### Method 1: Using CMake (Recommended)
```bash
# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Compile the project
make

# Run the program
./dataStructures-and-algorithms
```

#### Method 2: Direct GCC Compilation
```bash
# Compile all source files
gcc -std=c23 -Wall -Wextra -Werror -c STACK.c Depth-First-Search.c AVL_TREE.c Queue.c ArrayList.c LinkedList.c Heap.c

# Link and generate executable
gcc -std=c23 -Wall -Wextra -Werror main.c STACK.o Depth-First-Search.o AVL_TREE.o Queue.o ArrayList.o LinkedList.o Heap.o -lm -o dataStructures-and-algorithms

# Run the program
./dataStructures-and-algorithms
```

## 📁 Project Structure
```
.
├── CMakeLists.txt          # CMake configuration
├── main.c                  # Main program and test code
├── AVL_TREE.h/c           # AVL tree implementation
├── ArrayList.h/c          # Dynamic array implementation
├── LinkedList.h/c         # Doubly linked list implementation
├── STACK.h/c              # Stack implementation
├── Queue.h/c              # Queue implementation
├── Heap.h/c               # Heap implementation
└── Depth-First-Search.h/c # DFS algorithm implementation
```

## 📝 Usage Examples

### Create and Use Dynamic Array
```c
// Initialize array with capacity 10
ArrayList *list = initArrayList(10);

// Add elements
add(list, 5);
add(list, 3);
add(list, 8);

// Sort
quickSort(list, 0, list->index - 1);

// Print results
printArrayList(list);

// Free memory
destroyArrayList(list);
```

### Create and Use AVL Tree
```c
// Create empty tree
AVL_TreeNode *root = NULL;

// Insert elements
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 15);

// In-order traversal
inOrder(root);

// Free memory
destroyAVLTree(root);
```

## 🧪 Testing

The main.c file contains test code for all data structures and algorithms. You can uncomment specific test sections to run particular tests.

## 📄 License

This project is for educational and learning purposes only.

## 🤝 Contributing

Issues and Pull Requests are welcome to improve the code or add new data structures and algorithms.

## 📚 References

- Introduction to Algorithms (CLRS)
- Data Structures and Algorithm Analysis