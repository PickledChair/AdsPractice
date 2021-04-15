#include <iostream>
using namespace std;

int main() {
    cout << "Start Game!" << endl;

    // A さんの数の候補を表す区間を、[left, right) と表す
    int left = 20, right = 36;

    // A さんの数を１つに絞れないうちは繰り返す
    while (right - left > 1) {
        int mid = left + (right - left) / 2;  // 区間の真ん中

        // 「mid 以上か」を聞いて、回答を yes/no で受け取る
        cout << "Is the age less than " << mid << " ? (yes / no)" << endl;
        string ans;
        cin >> ans;

        // 回答に応じて、ありうる数の範囲を絞る
        if (ans == "yes") right = mid;
        else left = mid;
    }

    // ズバリ当てる！
    cout << "The age is " << left << "!" << endl;
}
