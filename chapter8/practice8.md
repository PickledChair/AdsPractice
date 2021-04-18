# 第8章の章末問題の解答

## 注意

公式の解答は未公開であり、解答の正誤を確認しておりません。



## 問題8.1

連結リストのサイズを N として、O(N)



## 問題8.2

`get(i)` 関数は i = 0 のとき O(1), i = 1 のとき O(2), …, i = N - 1 のとき O(N) で i 番目の要素を取得する。

問題のコードは以下の通り：

```c++
for (int i = 0; i < N; ++i) {
  cout << get(i) << endl;
}
```

i = 0, 1, …, N - 1 のそれぞれの場合で１回ずつ `get(i)` 関数を実行しているので、このコードの計算量は 1 + 2 + … + N = N(N + 1) / 2 = O(N^2)



## 問題8.3

本文の単方向連結リストであれば、以下のようにグローバル変数でリストのサイズを持っておいて、ノードの挿入時にカウントを増やすと良い。

```c++
struct Node {
  Node* next;  // 次がどのノードを指すか
  string name; // ノードに付随している値

  Node(string name_ = "") : next(NULL), name(name_) {}
}

// 番兵を表すノードをグローバル領域に置いておく
Node* nil;

// 連結リストのサイズを表す変数をグローバル領域に置いておく
size_t cnt = 0;

// 初期化
void init() {
  nil = new Node();
  nil->next = nil;  // 初期状態では nil が nil を指すようにする
  cnt = 0;          // 初期状態では連結リストのサイズは 0
}

// ノード p の直後にノード v を挿入する
// ノード p のデフォルト引数を nil としておく
// そのため insert(v) を呼び出す操作は、リストの先頭への挿入を表す
void insert(Node* v, Node* p = nil) {
  v->next = p->next;
  p->next = v;
  ++cnt;  // ノードの挿入に伴って増えた連結リストのサイズを cnt に反映する
}
```

`cnt` 変数を通じて連結リストのサイズを O(1) で得ることができる。ノードの削除時には `--cnt` とすればよい。双方向連結リストにおいても同様である（[コード例](https://github.com/PickledChair/AdsPractice/blob/main/chapter8/practice8_3/practice8_3.cpp)）。



## 問題8.4

次のように実装する。`nil->next` から順番に次のノードにアクセスし、最悪の場合それを終端の `nil` で止まるまでに N 個のノードに対して繰り返すので、計算量は O(N) である：

```c++
void erase(Node* v) {
  Node* prev = nil;
  Node* cur = nil->next;
  while (cur != nil) {
    if (cur == v) {
      prev->next = v->next;
      delete v;
      return;
    }
    prev = cur;
    cur = cur.next;
  }
}
```

