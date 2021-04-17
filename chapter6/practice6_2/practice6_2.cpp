#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long result = 0;

    for (int i = 0; i < N; ++i) {
        long long a_num = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        long long c_num = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        result += a_num * c_num;
    }

    cout << result << endl;
}
