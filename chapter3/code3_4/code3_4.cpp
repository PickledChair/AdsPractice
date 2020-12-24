#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;  // 十分大きな値に

int main() {
	// 入力を受け取る
	int N, K;
	cin >> N >> K;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < N; ++i) cin >> b[i];
	
	// 線形探索
	int min_value = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
            int cur_value = a[i] + b[j];
			// 和が K 未満の場合は捨てる
			if (cur_value < K) continue;
			
			// 最小値を更新
			if (cur_value < min_value) {
				min_value = cur_value;
			}
		}
	}
	
	// 結果出力
	cout << min_value << endl;
}