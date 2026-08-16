#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
   // DIVIDE & CONQUER OPTIMISED APPROACH (merge sort) - nlog(n) //
       if(head == nullptr || head->next == nullptr) {
        return head;
       }

    ListNode* slow = head;
    ListNode* fast = head->next;  // we want slow to stop at end of left half

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHead = slow->next;
    slow->next = nullptr;      // to divide the nodes 
  
    ListNode* left = sortList(head);
    ListNode* right = sortList(secondHead);

    return merge(left, right);
    }
 
 // now here we will do the "merge two sorted list" code to finally merge the splits //
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }

        if (a != nullptr) {
           curr->next = a;
         }
          else {
           curr->next = b;
         }
        return dummy.next;
    }
};