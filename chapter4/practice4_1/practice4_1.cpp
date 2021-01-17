#include <iostream>

int tribo(int N) {
    if (N == 0 || N == 1) return 0;
    else if (N == 2) return 1;

    return tribo(N - 1) + tribo(N - 2) + tribo(N - 3);
}

int main() {
    std::cout << tribo(9) << std::endl;
}
