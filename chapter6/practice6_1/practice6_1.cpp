#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> a(N), t(N);
    vector<size_t> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        t[i] = a[i];
    }

    sort(t.begin(), t.end());
    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(t.begin(), t.end(), a[i]);
        // size_t num = distance(t.begin(), iter);
        size_t num = iter - t.begin();
        r[i] = num;
    }

    for (int i = 0; i < N; ++i) {
        cout << r[i] << endl;
    }
}