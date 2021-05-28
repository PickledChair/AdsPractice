#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// cf. https://outline.hatenadiary.jp/entry/2020/02/17/153336
int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    sort(b.begin(), b.end());

    long long ng = 0, ok = 1 << 29;
    while (ok - ng > 1) {
        long long mid = (ng + ok) / 2, cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += upper_bound(b.begin(), b.end(), mid / a[i]) - b.begin();
        }
        if (cnt >= K) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
