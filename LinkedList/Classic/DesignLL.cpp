#include <vector>
#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {

    struct Node {
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~MyLinkedList() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        // Insert at head
        if (index == 0) {
            addAtHead(val);
            return;
        }

        // Insert at tail
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* curr = head;

        // Move to node before index
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        curr->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        // Delete head
        if (index == 0) {
            Node* temp = head;

            head = head->next;

            delete temp;
            size--;

            return;
        }

        Node* curr = head;

        // Move to node before index
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* temp = curr->next;

        curr->next = temp->next;

        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index, val);
 * obj->deleteAtIndex(index);
 */