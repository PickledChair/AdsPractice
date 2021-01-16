#include <iostream>

int fibo(int N) {
	// ベースケース
  if (N == 0) return 0;
  else if (N == 1) return 1;

  // 再帰呼び出し
  return fibo(N - 1) + fibo(N - 2);
}

int main() {
	std::cout << fibo(6) << std::endl;
	// std::cout << fibo(50) << std::endl; // 計算がなかなか終わらない
}
