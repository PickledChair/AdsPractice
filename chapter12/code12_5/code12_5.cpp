#include <iostream>
#include <vector>

const int MAX = 100000; // ここでは配列の値は 100000 未満とする

// バケットソート
void BucketSort(std::vector<int> &a) {
    int N = (int)a.size();

    // 各要素の個数をカウントする
    // num[v]: v の個数
    std::vector<int> num(MAX, 0);
    for (int i = 0; i < N; ++i) {
        ++num[a[i]]; // a[i] をカウントする
    }

    // num の累積和をとる
    // sum[v]: v 以下の値の個数
    // 値 a[i] が全体の中で何番目に小さいかを求める
    std::vector<int> sum(MAX, 0);
    sum[0] = num[0]; // サンプルコードにはないが、これがないと配列の要素に 0 が含まれていた場合に対応できない
    for (int v = 1; v < MAX; ++v) {
        sum[v] = sum[v - 1] + num[v];
    }

    // sum をもとにソート処理
    // a2: a をソートしたもの
    std::vector<int> a2(N);
    for (int i = N - 1; i >= 0; --i) {
        a2[--sum[a[i]]] = a[i];
    }
    a = a2;
}

int main() {
    // 入力
    int N; // 要素数
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    // バケットソート
    BucketSort(a);

    // ソート後の配列を表示
    for (int i = 0; i < N; ++i) std::cout << a[i];
    std::cout << std::endl;

    return 0;
}
