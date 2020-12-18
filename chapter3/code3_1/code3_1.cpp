#include <iostream>
#include <vector>

int main() {
    // 入力を受け取る
    int N, v;
    std::cin >> N >> v;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    // 線形探索
    bool exist = false;  // 初期値は false に
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            exist = true;  // 見つかったらフラグを立てる
        }
    }

    // 結果出力
    if (exist) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}