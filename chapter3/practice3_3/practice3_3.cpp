#include <iostream>
#include <vector>
const int INF = 20000000;

int main() {
    int N;
    std::cout << "数列のサイズを入力> ";
    std::cin >> N;

    if (N < 2) {
        std::cout << "数列のサイズが2以上ではありません" << std::endl;
        std::exit(1);
    }

    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cout << i << "番目の整数を入力> ";
        std::cin >> a[i];
    }

    int firstMin = INF;
    int secondMin = INF + 1;

    for (int i = 0; i < N; ++i) {
        if (a[i] < firstMin) {
            secondMin = firstMin;
            firstMin = a[i];
            continue;
        }

        if (a[i] < secondMin) {
            secondMin = a[i];
            continue;
        }
    }

    std::cout << "2番目に小さい値は" << secondMin << "です" << std::endl;
}