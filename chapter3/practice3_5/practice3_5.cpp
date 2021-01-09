#include <iostream>
#include <vector>
const int INF = 20000000;

int main() {
    int N;
    std::cout << "数列のサイズを入力> ";
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cout << i << "番目の整数を入力> ";
        std::cin >> a[i];
    }

    int min = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < min; ++j) {
            if (a[i] & (1 << j)) {
                min = j;
                break;
            }
        }
    }

    std::cout << min << "回の操作を行うことになる" << std::endl;
}