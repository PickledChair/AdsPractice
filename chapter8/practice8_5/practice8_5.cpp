#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> a(N), b(M);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int j = 0; j < M; ++j) cin >> b[j];

    unordered_set<long long> S;
    for (int i = 0; i < N; ++i) S.insert(a[i]);
    int result = 0;
    for (int j = 0; j < M; ++j) {
        if (S.find(b[j]) != S.end()) ++result;
    }
    cout << result << endl;
}
