#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T> void chmax(T& a, T b) {
    if (b > a) {
        a = b;
    }
}

int main() {
    // 入力
    string S, T;
    cin >> S >> T;

    // DP テーブル定義
    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));

    // DP ループ
    for (int i = 0; i < S.size(); ++i) {
        for (int j = 0; j < T.size(); ++j) {
            if (S[i] == T[j]) {
                chmax(dp[i+1][j+1], dp[i][j] + 1);
            }
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    // 答えの出力（dp には部分文字列の最大長が記録されているだけなので、文字列を導く必要がある）
    string result = "";
    int i = S.size(), j = T.size();
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
            // (i-1, j) -> (i, j)
            --i;
        } else if (dp[i][j] == dp[i][j-1]) {
            // (i, j-1) -> (i, j)
            --j;
        } else {
            // (i-1, j-1) -> (i, j)
            result = S[i-1] + result;
            --i; --j;
        }
    }
    cout << result << endl;
}
