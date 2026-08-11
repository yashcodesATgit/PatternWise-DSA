#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) { // constructor
        data = x;
        next = NULL;
    }
};

        // Iterative approach // 
class Solution {
  public:
    bool searchKey(Node* head, int key) {
         
         Node* curr = head;
         
         while(curr != nullptr) {
            
             if(curr->data == key) {
                 return true;
             }
             curr = curr->next;
         }
         
         return false;
    }
};

/*
 // Recursive approach //
class Solution {
  public:
    bool searchKey(Node* head, int key) {
         
         Node* curr = head;
         
         while(curr != nullptr) {
            
             if(curr->data == key) {
                 return true;
             }
             curr = curr->next;
         }
         
         return false;
    }
}; 
*/          


