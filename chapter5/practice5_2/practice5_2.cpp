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
            // 前のループまでに部分問題の答えが記録されている
            if (!dp[i][w]) continue;
            // 先頭から i 個の整数の場合に true なら、今後いくら整数を増やしても
            // 必ず適した組み合わせがあるので、true を代入
            dp[i + 1][w] = true;
            // 先頭から i 個の整数の場合に true なので、i + 1 個の時に合計が
            // w + a[i] になる組み合わせがある。なのでテーブルの該当箇所に true を代入
            if (w + a[i] <= W) dp[i + 1][w + a[i]] = true;
        }
    }

    // 答え
    if (dp[N][W]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}