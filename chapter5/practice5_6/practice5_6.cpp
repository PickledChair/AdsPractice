#include <iostream>
#include <vector>
using namespace std;

template<typename T> void chmin(T& a, T b) {
    if (b < a) {
        a = b;
    }
}

const int INF = 1 << 29;

int main() {
    // データ入力
    int N, W;
    cin >> N >> W;

    vector<int> a(N), m(N);
    for (int i = 0; i < N; ++i) cin >> a[i] >> m[i];

    // DP テーブル定義
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));

    // 初期条件（ 0 個の整数の合計は常に 0 ）
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (dp[i][w] < INF) chmin(dp[i + 1][w], 0);
            if (dp[i + 1][w] < m[i] && w + a[i] <= W) {
                chmin(dp[i + 1][w + a[i]], dp[i + 1][w] + 1);
            }
        }
    }

    // 答え
    if (dp[N][W] < INF) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
