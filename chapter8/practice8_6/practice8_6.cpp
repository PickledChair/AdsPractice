#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

using entry = pair<long long, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> a(N), b(M);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < M; ++i) cin >> b[i];

    unordered_map<long long, int> mp;
    for (int i = 0; i < N; ++i) {
        mp[a[i]] += 1;
    }

    int result = 0;
    for (int j = 0; j < M; ++j) {
        result += mp[b[j]];
    }
    cout << result << endl;
}
