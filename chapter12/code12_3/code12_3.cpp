#include <iostream>
#include <vector>

// 配列 a の区間 [left, right) をソートする
// [left, right) は left, left+1, ..., right-1 番目を表す
void QuickSort(std::vector<int> &a, int left, int right) {
    if (right - left <= 1) return;

    int pivot_index = (left + right) / 2; // 適当にここでは中点とする
    int pivot = a[pivot_index];
    std::swap(a[pivot_index], a[right - 1]); // pivot と右端を swap

    int i = left; // i は左詰めされた pivot 未満要素の右端を表す
    for (int j = left; j < right - 1; ++j) {
        if (a[j] < pivot) { // pivot 未満のものがあったら左に詰めていく
            std::swap(a[i++], a[j]);
        }
    }
    std::swap(a[i], a[right - 1]); // pivot を適切な場所に挿入

    // 再帰的に解く
    QuickSort(a, left, i); // 左半分 (pivot 未満)
    QuickSort(a, i + 1, right); // 右半分 (pivot 以上)
}

int main() {
    // 入力
    int N; // 要素数
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    // クイックソート
    QuickSort(a, 0, N);

    // ソート後の配列を表示
    for (int i = 0; i < N; ++i) std::cout << a[i];
    std::cout << std::endl;

    return 0;
}
