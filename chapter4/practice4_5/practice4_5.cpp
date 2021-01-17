#include <iostream>

int count753(long long N, long long accum, int count3, int count5, int count7) {
    if (accum > N) return 0;

    int c = 0;
    if (count3 > 0 && count5 > 0 && count7 > 0) c = 1;
    else c = 0;

    return c + count753(N, accum*10 + 3, count3+1, count5, count7)
             + count753(N, accum*10 + 5, count3, count5+1, count7)
             + count753(N, accum*10 + 7, count3, count5, count7+1);
}

int main() {
    long long N;
    std::cin >> N;
    std::cout << count753(N, 0, 0, 0, 0) << std::endl;
}