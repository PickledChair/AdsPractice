#include <iostream>
#include <vector>

// 配列 a をソートする
void InsertionSort(std::vector<int> &a) {
    int N = (int)a.size();
    for (int i = 1; i < N; ++i) {
        int v = a[i]; // 挿入したい値

        // v を挿入する適切な j を探す
        int j = i;
        for (; j > 0; --j) {
            if (a[j-1] > v) { // v より大きいものは１つ後ろに移す
                a[j] = a[j-1];
            } else {
                break;
            }
        }
        a[j] = v; // 最後に j 番目に v を持ってくる
    }
}

int main() {
    // 入力
    int N; // 要素数
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    // 挿入ソート
    InsertionSort(a);

    // ソート後の配列を表示
    for (int i = 0; i < N; ++i) std::cout << a[i];
    std::cout << std::endl;

    return 0;
}
