#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

   ListNode(int x, ListNode* nextNode) {
    val = x;
    next = nextNode;
}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      
        if(head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* curr = head;
        int n = 1;              // length of nodes
        while(curr->next != nullptr) {
            curr = curr->next;
            n++;
        }

        k = k % n; 
        if(k == 0) return head;

        curr->next = head;   // temperory circular list formation

        ListNode* newTail = head;
        int steps = n - k - 1;    
        for(int i=0 ; i<steps; i++) {
            newTail = newTail->next;     // move upto disconnection node (n-k-1)
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;        // disconnect newTail and newHead

        return newHead;
    }
};