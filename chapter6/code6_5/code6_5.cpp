#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> h(N), s(N);
    for (int i = 0; i < N; ++i) cin >> h[i] >> s[i];

    // 二分探索
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long mid = (left + right) / 2;

        // 判定（全ての風船について、これから算出する制限時間をクリアできるかどうか）
        bool ok = true;
        vector<long long> t(N, 0);  // 各風船を割るまでの時間制限
        for (int i = 0; i < N; ++i) {

            if (mid < h[i]) {
                // 最初から mid (目標高度) が初期高度より低かったら false
                ok = false;
            } else {
                // 制限時間 = (目標高度 - 初期高度) / １秒あたりの上昇高度
                t[i] = (mid - h[i]) / s[i];
            }
        }
        // 時間制限が差し迫っている順にソート
        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i) {
            // １秒あたり１個の風船を割れるので、ソート後の風船の i 番目のものは
            // i 秒後に割れる必要がある（ i = 0 の場合は今すぐに割る）
            if (t[i] < i) {
                ok = false;  // 時間切れ発生
            }
        }

        if (ok) {
            // 時間内に全ての風船を割れる場合は、もっとギリギリを攻められるかどうか
            // 試すため、高度の列のうち左側を探索する
            right = mid;
        } else {
            // 時間制限をクリアできなかった場合は、もっと緩い条件の中からクリアできる
            // 最小の高度を選ぶため、高度の列の右側を探索する
            left = mid;
        }
    }

    cout << right << endl;
}