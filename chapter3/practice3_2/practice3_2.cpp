#include <iostream>
#include <vector>

int main() {
    int N, V;
    std::cin >> N >> V;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] == V) {
            ++count;
        }
    }

    std::cout << "整数値" << V << "は" << count << "個ありました。" << std::endl;
}