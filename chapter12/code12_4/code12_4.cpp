#include <iostream>
#include <vector>

// i 番目の頂点を根とする部分木について、ヒープ条件を満たすようにする
// a のうち 0 番目から N-1 番目までの部分 a[0:N] についてのみ考える
void Heapify(std::vector<int> &a, int i, int N) {
    int child1 = i * 2 + 1; // 左の子供
    if (child1 >= N) return; // 子供がないときは終了

    // 子供同士を比較
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;

    if (a[child1] <= a[i]) return; // 逆転がなかったら終了

    // swap
    std::swap(a[i], a[child1]);

    // 再帰的に
    Heapify(a, child1, N);
}

// 配列 a をソートする
void HeapSort(std::vector<int> &a) {
    int N = (int)a.size();

    // ステップ１：a 全体をヒープにするフェーズ
    for (int i = N / 2 - 1; i >= 0; --i) {
        Heapify(a, i, N);
    }

    // ステップ２：ヒープから１個１個最大値を pop するフェーズ
    for (int i = N - 1; i > 0; --i) {
        std::swap(a[0], a[i]); // ヒープの最大値を左詰め
        Heapify(a, 0, i); // ヒープサイズは i に
    }
}

int main() {
    // 入力
    int N; // 要素数
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    // ヒープソート
    HeapSort(a);

    // ソート後の配列を表示
    for (int i = 0; i < N; ++i) std::cout << a[i];
    std::cout << std::endl;

    return 0;
}
