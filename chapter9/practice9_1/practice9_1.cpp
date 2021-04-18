#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 連結リストの各ノードを表す構造体
struct Node {
    Node *prev, *next;
    int value;  // ノードに付随している値

    Node(int value_ = 0) :
    prev(NULL), next(NULL), value(value_) {}
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

    void PrintList() {
        Node* cur = nil->next;
        for (; cur != nil; cur = cur->next) {
            cout << cur->value << " -> ";
        }
        cout << endl;
    }

    void Insert(Node* v, Node* p) {
        v->next = p->next;
        p->next->prev = v;
        p->next = v;
        v->prev = p;
        ++size;
    }

    void Insert(Node* v) {
        Insert(v, nil);
    }

    void Erase(Node *v) {
        if (v == nil) return;
        v->prev->next = v->next;
        v->next->prev = v->prev;
        delete v;
        --size;
    }

    size_t Length() {
        return size;
    }
};

struct Stack {
    LinkedList* list;
    Node* top;

    Stack() : top(NULL) {
        list = new LinkedList;
    }

    void Push(int x) {
        Node *node = new Node(x);
        top = node;
        list->Insert(node);
    }

    int Pop() {
        int res;
        if (top == NULL) {
            res = -1;
        } else {
            res = top->value;
            Node* tmp = top->next;
            list->Erase(top);
            top = tmp;
        }
        return res;
    }
};

struct Queue {
    LinkedList *list;
    Node *head, *tail;

    Queue() : head(NULL), tail(NULL) {
        list = new LinkedList;
    }

    void Enqueue(int x) {
        Node* node = new Node(x);
        list->Insert(node);
        head = list->nil->prev;
        tail = list->nil->next;
    }

    int Dequeue() {
        int res;
        if (head == NULL) {
            res = -1;
        } else {
            res = head->value;
            Node* tmp = head->prev;
            list->Erase(head);
            head = tmp;
        }
        return res;
    }
};

int main() {
    Stack* st = new Stack;

    st->Push(3);  // スタックに 3 を挿入する {} -> {3}
    st->Push(5);  // スタックに 5 を挿入する {3} -> {3, 5}
    st->Push(7);  // スタックに 7 を挿入する {3, 5} -> {3, 5, 7}

    cout << st->Pop() << endl;  // {3, 5, 7} -> {3, 5} で 7 を出力
    cout << st->Pop() << endl;  // {3, 5} -> {3} で 5 を出力

    st->Push(9);  // 新たに 9 を挿入する {3} -> {3, 9}

    Queue* qu = new Queue;

    qu->Enqueue(3);  // キューに 3 を挿入する {} -> {3}
    qu->Enqueue(5);  // キューに 5 を挿入する {3} -> {3, 5}
    qu->Enqueue(7);  // キューに 7 を挿入する {3, 5} -> {3, 5, 7}

    cout << qu->Dequeue() << endl;  // {3, 5, 7} -> {5, 7} で 3 を出力
    cout << qu->Dequeue() << endl;  // {5, 7} -> {7} で 5 を出力

    qu->Enqueue(9);  // 新たに 9 を挿入する {7} -> {7, 9}
}