#include <iostream>
#include <vector>
using namespace std;

int tribo(int N, vector<long long>& memo) {
    if (N == 0 || N == 1) return 0;
    else if (N == 2) return 1;

    if (memo[N] != -1) return memo[N];

    return memo[N] = tribo(N - 1, memo) + tribo(N - 2, memo) + tribo(N - 3, memo); 
}

int main() {
    vector<long long> memo;
    memo.assign(30, -1);

    tribo(29, memo);

    for (int i = 3; i < 30; ++i) {
        cout << "第 " << i << " 項: " << memo[i] << endl;
    }
}
