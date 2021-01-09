#include <iostream>
#include <vector>

int main() {
    int K, N;
    std::cout << "Kの値> ";
    std::cin >> K;
    std::cout << "Nの値> ";
    std::cin >> N;

    int count = 0;
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (N - i - j < 0 || N - i - j > K) {
                continue;
            } else {
                ++count;
            }
        }
    }

    std::cout << count << "通りある" << std::endl;
}