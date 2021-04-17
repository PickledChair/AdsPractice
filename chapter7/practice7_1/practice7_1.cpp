#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 注：公式解答が未公開のため、正誤は未確認

int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int result = 0, i = 0, j = 0;
    while (i < N && j < N) {
        if (a[i] < b[j]) {
            ++result; ++i; ++j;
        } else {
            ++j;
        }
    }
    cout << result << endl;
}
