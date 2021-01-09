#include <iostream>
#include <vector>
const int INF = 20000000;

int main() {
    int N;
    std::cout << "数列のサイズを入力> ";
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cout << i << "番目の整数を入力> ";
        std::cin >> a[i];
    }

    int min = INF;
    int max = -INF;

    for (int i = 0; i < N; ++i) {
        if (a[i] < min) {
            min = a[i];
        }

        if (a[i] > max) {
            max = a[i];
        }
    }

    std::cout << "最小値: " << min << ", 最大値: " << max << ", 最大の差: " << max - min << std::endl;
}