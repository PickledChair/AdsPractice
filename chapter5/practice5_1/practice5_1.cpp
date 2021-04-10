#include <iostream>
#include <vector>
using namespace std;

template<typename T> void chmax(T& a, T b) {
    if (b > a) {
        a = b;
    }
}

int main() {
    // 入力
    int N;
    cin >> N;
    const int a = 0;
    const int b = 1;
    const int c = 2;
    vector<vector<long long>> happiness(3, vector<long long>(N));

    for (int kind = 0; kind < 3; ++kind) {
        for (int date = 0; date < N; ++date) {
            cin >> happiness[kind][date];
        }
    }

    // DP テーブル定義
    vector<vector<long long>> dp(3, vector<long long>(N + 1, 0));

    // DP ループ
    for (int kind = 0; kind < 3; ++kind) {
        for (int date = 0; date < N; ++date) {
            switch (kind) {
            case a:
                chmax(dp[a][date+1], dp[b][date] + happiness[a][date]);
                chmax(dp[a][date+1], dp[c][date] + happiness[a][date]);
                continue;
            case b:
                chmax(dp[b][date+1], dp[a][date] + happiness[b][date]);
                chmax(dp[b][date+1], dp[c][date] + happiness[b][date]);
                continue;
            case c:
                chmax(dp[c][date+1], dp[a][date] + happiness[c][date]);
                chmax(dp[c][date+1], dp[b][date] + happiness[c][date]);
                continue;
            }
        }
    }

    // 答えの出力
    long long result = 0;

    for (int i = 0; i < 3; ++i) {
        chmax(result, dp[i][N]);
    }

    cout << result << endl;
}
