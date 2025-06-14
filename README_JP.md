# データ構造とアルゴリズム

C言語で実装された一般的なデータ構造と古典的なアルゴリズムの学習プロジェクトです。

## 📚 実装されたデータ構造

### 1. AVL木（AVL Tree）
- 自己平衡二分探索木
- 挿入、削除、検索操作をサポート
- 前順、中順、後順、レベル順走査を含む
- 木の視覚化印刷機能を提供

### 2. 動的配列（ArrayList）
- 動的に拡張・縮小可能な配列
- 基本的な追加・削除・取得・設定操作をサポート
- 複数のソートアルゴリズムを統合
- 二分探索をサポート

### 3. 双方向連結リスト（Doubly Linked List）
- 前後のポインタを持つ連結リスト
- 各ノードに一意の識別子
- マージソートをサポート

### 4. スタック（Stack）
- 連結リストベースの実装
- push、pop、peek操作をサポート
- 木の走査に使用

### 5. キュー（Queue）
- 連結リストベースの実装
- エンキュー、デキュー操作をサポート
- 木のレベル順走査に使用

### 6. ヒープ（Heap）
- 配列ベースの二分ヒープ実装
- ヒープ化操作をサポート
- 優先度キューやTopK問題に使用可能

## 🔧 実装されたアルゴリズム

### ソートアルゴリズム
| アルゴリズム | 平均時間計算量 | 空間計算量 | 安定性 |
|------------|--------------|-----------|--------|
| バブルソート | O(n²) | O(1) | 安定 |
| 選択ソート | O(n²) | O(1) | 不安定 |
| 挿入ソート | O(n²) | O(1) | 安定 |
| マージソート | O(n log n) | O(n) | 安定 |
| クイックソート | O(n log n) | O(log n) | 不安定 |
| バケットソート | O(n + k) | O(n + k) | 安定 |
| 計数ソート | O(n + k) | O(k) | 安定 |
| 基数ソート | O(d × n) | O(n + k) | 安定 |

### 探索アルゴリズム
- **二分探索**: ソート済み配列での探索、時間計算量 O(log n)
- **深さ優先探索（DFS）**: 木の走査に使用
- **幅優先探索（BFS）**: 木のレベル順走査に使用

### その他のアルゴリズム
- **Fisher-Yatesシャッフル**: 配列をランダムにシャッフル
- **TopKアルゴリズム**: ヒープを使用して最大K個の要素を見つける

## 🛠️ ビルドと実行

### 必要環境
- Cコンパイラ（C23標準対応）
- CMake 3.30以上

### ビルド手順

#### 方法1: CMakeを使用（推奨）
```bash
# ビルドディレクトリを作成
mkdir build
cd build

# ビルドファイルを生成
cmake ..

# プロジェクトをコンパイル
make

# プログラムを実行
./dataStructures-and-algorithms
```

#### 方法2: GCCを直接使用
```bash
# すべてのソースファイルをコンパイル
gcc -std=c23 -Wall -Wextra -Werror -c STACK.c Depth-First-Search.c AVL_TREE.c Queue.c ArrayList.c LinkedList.c Heap.c

# リンクして実行ファイルを生成
gcc -std=c23 -Wall -Wextra -Werror main.c STACK.o Depth-First-Search.o AVL_TREE.o Queue.o ArrayList.o LinkedList.o Heap.o -lm -o dataStructures-and-algorithms

# プログラムを実行
./dataStructures-and-algorithms
```

## 📁 プロジェクト構造
```
.
├── CMakeLists.txt          # CMake設定ファイル
├── main.c                  # メインプログラムとテストコード
├── AVL_TREE.h/c           # AVL木の実装
├── ArrayList.h/c          # 動的配列の実装
├── LinkedList.h/c         # 双方向連結リストの実装
├── STACK.h/c              # スタックの実装
├── Queue.h/c              # キューの実装
├── Heap.h/c               # ヒープの実装
└── Depth-First-Search.h/c # DFSアルゴリズムの実装
```

## 📝 使用例

### 動的配列の作成と使用
```c
// 容量10の配列を初期化
ArrayList *list = initArrayList(10);

// 要素を追加
add(list, 5);
add(list, 3);
add(list, 8);

// ソート
quickSort(list, 0, list->index - 1);

// 結果を出力
printArrayList(list);

// メモリを解放
destroyArrayList(list);
```

### AVL木の作成と使用
```c
// 空の木を作成
AVL_TreeNode *root = NULL;

// 要素を挿入
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 15);

// 中順走査
inOrder(root);

// メモリを解放
destroyAVLTree(root);
```

## 🧪 テスト

main.cファイルには、すべてのデータ構造とアルゴリズムのテストコードが含まれています。特定のテストセクションのコメントを解除して、特定のテストを実行できます。

## 📄 ライセンス

このプロジェクトは学習および教育目的のみです。

## 🤝 貢献

コードの改善や新しいデータ構造・アルゴリズムの追加のために、IssueやPull Requestを歓迎します。

## 📚 参考文献

- アルゴリズムイントロダクション（Introduction to Algorithms）
- データ構造とアルゴリズム解析（Data Structures and Algorithm Analysis）