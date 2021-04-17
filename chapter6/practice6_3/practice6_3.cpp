#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 入力
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    vector<long long> s;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            s.push_back(a[i] + a[j]);
        }
    }
    sort(s.begin(), s.end());

    long long result = 0;
    for (long long s_item : s) {
        auto iter = upper_bound(s.begin(), s.end(), M - s_item);
        if (iter == s.begin()) continue;
        --iter;
        result = max(result, s_item + *iter);
    }
    cout << result << endl;
}
