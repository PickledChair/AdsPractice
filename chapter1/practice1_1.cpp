#include <iostream>
#include <vector>
#include <algorithm>

void solver(int answer, int start, int end) {
    const int range = end - start;
    if (range%2 != 0) {
        std::cout << "\n年齢の範囲が2の倍数になっていません" << std::endl;
        exit(1);
    }
    const int half_range = range / 2;

    std::cout << "\t" << start + half_range << "歳未満ですか？";
    if (answer-start < end-answer) {
        std::cout << "-Yes";
        if (half_range > 1)
            solver(answer, start, start+half_range);
        else
            return;
    } else {
        std::cout << "-No";
        if (half_range > 1)
            solver(answer, end-half_range, end);
        else
            return;
    }
}

int main() {
    std::vector<int> ages;
    const int start = 20;
    int tmp = start;
    const int end = 36;

    while (tmp < end) {
        ages.push_back(tmp);
        tmp++;
    }

    auto print_result = [start, end](int ans) {
        std::cout << "答え:" << ans << "歳";
        solver(ans, start, end);
        std::cout << std::endl;
    };
    std::for_each(ages.begin(), ages.end(), print_result);
    return 0;
}