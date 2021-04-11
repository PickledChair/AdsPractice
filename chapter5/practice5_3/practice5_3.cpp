#include <iostream>
#include <vector>
using namespace std;

int main() {
    // データ入力
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // DP テーブル定義
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));

    // 初期条件（ 0 個の整数の合計は常に 0 ）
    dp[0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (!dp[i][w]) continue;
            dp[i + 1][w] = true;
            if (w + a[i] <= W) dp[i + 1][w + a[i]] = true;
        }
    }

    // 答え
    int result = 0;
    for (int w = 1; w <= W; ++w) {
        if (dp[N][w]) {
            result += 1;
        }
    }
    cout << result << endl;
}
