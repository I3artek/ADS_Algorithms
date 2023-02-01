#ifndef MIDTERM_TASK_2_QUEUE_H
#define MIDTERM_TASK_2_QUEUE_H

#define MAX_DIGITS 10

#include <iostream>
using namespace std;

struct Node {
    char val[MAX_DIGITS];
    Node* next;

    Node(int v) {
        //this->val = v;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void Put(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
            return;
        }
        Node* temp = new Node(val);
        tail->next = temp;
        tail = tail->next;
    }

    int Get() {
        if (head == NULL) {
            throw invalid_argument("Invalid arg");
        }
        int val = head->val;
        if (head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        return val;
    }

    bool Empty() {
        return head == NULL;
    }
};

#endif //MIDTERM_TASK_2_QUEUE_H
