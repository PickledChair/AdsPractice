#include <iostream>
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

int main() {
    string buffer;

    while (true) {
        init();

        cin >> buffer;
        if (buffer == "exit") break;

        for (int i = 0; i < (int)buffer.size(); ++i) {

            char ch = buffer[i];
            if ('0' <= ch && ch <= '9') {
                push(int(ch - '0'));
                continue;
            }

            int snd = pop();
            int fst = pop();

            switch (ch) {
            case '+': push(fst + snd); continue;
            case '-': push(fst - snd); continue;
            case '*': push(fst * snd); continue;
            case '/': push(fst / snd); continue;
            default:
                cout << "illegal character: " << ch << endl;
                break;
            }
        }
        cout << pop() << endl;
        buffer.clear();
    }
}