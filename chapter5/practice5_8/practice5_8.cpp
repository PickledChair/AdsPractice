#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template<typename T> void chmax(T& a, T b) {
    if (b > a) {
        a = b;
    }
}

const long long INF = 1LL << 60;

double average(int j, int i, const vector<long long>& a, vector<vector<double>>& av_table) {
    if (av_table[j][i] > 0) {
        return av_table[j][i];
    }
    double sum = 0;
    for (int k = j; k < i; ++k) sum += a[k];
    av_table[j][i] = sum / (i - j);
    return av_table[j][i];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    vector<vector<double>> av_table(N+1, vector<double>(N+1, -INF));

    // DP テーブル定義
    vector<vector<double>> dp(N+1, vector<double>(M+1, -INF));
    dp[0][0] = 0;

    // DP ループ
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 1; k <= M; ++k) {
                chmax(dp[i][k], dp[j][k-1] + average(j, i, a, av_table));
            }
        }
    }

    // 結果
    cout << fixed << setprecision(10) << dp[N][M] << endl;
}
