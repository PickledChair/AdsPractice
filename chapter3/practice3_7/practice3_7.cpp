#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;
    std::cout << "文字列S> ";
    std::cin >> S;
    N = S.length();

    int sum = 0;
    int start = 0;
    int buf = 0;
    for (int bit = 0; bit < (1 << (N-1)); ++bit) {
        start = 0;
        for (int i = 0; i < N-1; ++i) {
            if (bit & (1 << i)) {
                buf = std::stoi(S.substr(start, i+1 - start));
                std::cout << buf << "+";
                sum += buf;
                start = i+1;
            }
            if (i == N-2) {
                buf = std::stoi(S.substr(start, N - start));
                std::cout << buf << std::endl;
                sum += buf;
            }
        }
    }

    std::cout << sum << std::endl;
}