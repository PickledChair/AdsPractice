#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 連結リストの各ノードを表す構造体
struct Node {
    Node *prev, *next;
    string name;  // ノードに付随している値

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) {}
};

struct LinkedList {
    Node* nil;
    size_t size;

    LinkedList() {
        nil = new Node();
        nil->prev = nil;
        nil->next = nil;
        size = 0;
    }

    void print_list() {
        Node* cur = nil->next;
        for (; cur != nil; cur = cur->next) {
            cout << cur->name << " -> ";
        }
        cout << endl;
    }

    void insert(Node* v, Node* p) {
        v->next = p->next;
        p->next->prev = v;
        p->next = v;
        v->prev = p;
        ++size;
    }

    void insert(Node* v) {
        insert(v, nil);
    }

    void erase(Node *v) {
        if (v == nil) return;
        v->prev->next = v->next;
        v->next->prev = v->prev;
        delete v;
        --size;
    }

    size_t length() {
        return size;
    }
};

int main() {
    // 初期化
    LinkedList* list = new LinkedList;
    cout << "the size of the list: " << list->length() << endl;

    // 作りたいノードの名前の一覧
    // 最後尾のノード（「山本」）から順に挿入することに注意
    vector<string> names = {
        "yamamoto",
        "watanabe",
        "ito",
        "takahashi",
        "suzuki",
        "sato",
    };

    // 連結リスト作成：各ノードを生成して、連結リストの先頭に挿入していく
    Node *watanabe;
    for (int i = 0; i < (int)names.size(); ++i) {
        // ノードを作成する
        Node* node = new Node(names[i]);

        // 作成したノードを連結リストの先頭に挿入する
        list->insert(node);

        // 「渡辺」ノードを保持しておく
        if (names[i] == "watanabe") watanabe = node;
    }

    // 「渡辺」ノードを削除する
    cout << "before: ";
    list->print_list();  // 削除前を出力
    cout << "the size of the list: " << list->length() << endl;
    list->erase(watanabe);
    cout << "after: ";
    list->print_list();  // 削除後を出力
    cout << "the size of the list: " << list->length() << endl;
}
