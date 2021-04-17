#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    // 「全ての間隔を x 以上にして M 個の小屋を選べるか？」という判定問題を解く
    // Yes であるような最大の x を求める
    long long right = 0, left = INF;
    while (right - left > 1) {
        long long x = (left + right) / 2;

        int cnt = 1;   // 何個の小屋を選べたか（最初の小屋は必ず選ぶので、初期値は１）
        int prev = 0;  // 前の小屋のインデックス
        for (int i = 0; i < N; ++i) {
            // x 以上の間隔が開いたら採用する
            if (a[i] - a[prev] >= x) {
                ++cnt;
                prev = i;
            }
        }

        // 判定問題が Yes か No か
        if (cnt >= M) left = x;
        else right = x;
    }
    cout << left << endl;
}
