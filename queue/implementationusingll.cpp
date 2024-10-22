#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void push(int data) {
        Node* newnode = new Node(data);
        if (head == NULL) { // Fixed the comparison here
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty:" << endl;
            return; // Return immediately after printing the message
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) { // If the queue becomes empty after pop
            tail = NULL; // Ensure tail is also set to NULL
        }
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty:" << endl;
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return head == NULL; // Fixed the comparison here
    }
};

int main() {
    Queue q;
    for (int i = 0; i <= 6; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
