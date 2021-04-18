#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    unordered_set<long long> us;
    for (int i = 0; i < N; ++i) {
        us.insert(K - a[i]);
    }

    bool result = false;
    for (int i = 0; i < N; ++i) {
        if (us.find(b[i]) != us.end()) {
            result = true;
            break;
        }
    }
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
