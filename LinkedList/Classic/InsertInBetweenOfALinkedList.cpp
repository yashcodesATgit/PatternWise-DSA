#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int x) { // constructor
        val = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* insertInBetween(Node* head, int x, int position) {

        Node* newNode = new Node(x);

        if (head == nullptr) {
            return newNode;
        }

        Node* curr = head;

        // Move curr to the node after which we want to insert
        for (int i = 1; i < position; i++) {
            curr = curr->next;
        }

        // Connect newNode between curr and curr->next
        newNode->next = curr->next;
        curr->next = newNode;

        return head;
    }
};