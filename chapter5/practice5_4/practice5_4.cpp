#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 29;

template<typename T> void chmin(T& a, T b) {
    if (b < a) {
        a = b;
    }
}

int main() {
    // データ入力
    int N, W, K;
    cin >> N >> W >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // DP テーブル定義
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));

    // 初期条件（ 0 個の整数の合計は常に 0 ）
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {
            chmin(dp[i + 1][w], dp[i][w]);
            if (w >= a[i]) chmin(dp[i + 1][w], dp[i][w - a[i]] + 1);
        }
    }

    // 答え
    if (dp[N][W] <= K) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
