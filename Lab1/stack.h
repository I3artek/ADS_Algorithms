#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int val;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};


class Stack {
    Node* head;
public:
    Stack() {
        head = NULL;
    }

    void Put(int val) {
        if (head == NULL) {
            head = new Node(val);
            return;
        }
        Node* tmp = new Node(val);
        tmp->next = head;
        head = tmp;
    }

    int Get() {
        if (head == NULL) {
            return -1000;
        }
        int val = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    bool Empty() {
        return head == NULL;
    }
};
