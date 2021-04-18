#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 100000;
int st[MAX];
int top = 0;

void init() {
    top = 0;
}

bool isEmpty() {
    return (top == 0);
}

bool isFull() {
    return (top == MAX);
}

void push(int x) {
    if (isFull()) {
        cout << "error: stack is full." << endl;
        return;
    }
    st[top] = x;
    ++top;
}

int pop() {
    if (isEmpty()) {
        cout << "error: stack is empty." << endl;
        return -1;
    }
    --top;
    return st[top];
}

using ii = pair<int,int>;

int main() {
    // 入力
    string S;
    cin >> S;

    vector<ii> pairs;
    bool result = false;

    for (int i = 0; i < (int)S.size(); ++i) {
        if (S[i] == '(') {
            push(i);
        } else {
            if (isEmpty()) {
                break;
            } else {
                pairs.push_back(ii{pop(), i});
            }
        }

        if (i == (int)S.size() - 1) result = true;
    }
    result = isEmpty() && result;

    // 結果
    if (result) {
        cout << "yes" << endl;
        for (int j = 0; j < (int)pairs.size(); ++j) {
            cout << "(" << pairs[j].first << "," << pairs[j].second << ")" << endl;
        }
    } else {
        cout << "no" << endl;
    }
}
