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
    Node *insertAtEnd(Node *head, int x) {
           
           Node* newNode = new Node(x);
           
           if(head == nullptr) {
               return newNode;
           }
           
           Node* curr = head;
           
           while(curr->next != nullptr) {
               curr = curr->next;
           }
           
           curr->next = newNode;
           
           return head;
    }
};
