#include <iostream>
#include <vector>
#include "../common/union_find.hpp"
using namespace std;

// cf. https://drken1215.hatenablog.com/entry/2021/07/27/165300
int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        // 頂点番号の入力は1始まりだが、
        // 後で頂点１つ１つが根であるかどうか調べるのに
        // ループを0から始めるので、番号を1つ減らしている
        --A[i], --B[i];
    }

    // 各辺を除外して Union-Find で判定
    int res = 0;
    for (int e = 0; e < M; ++e) {
        UnionFind uf(N);
        for (int i = 0; i < M; ++i) {
            // 辺 e を除外
            if (i == e) continue;

            uf.unite(A[i], B[i]);
        }

        // 連結成分の個数を求める
        int num = 0;
        for (int v = 0; v < N; ++v) {
            if (uf.root(v) == v) ++num;
        }

        // 連結成分が 1 より大きいと非連結
        if (num > 1) ++res;
    }

    cout << res << endl;
}
