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

class Solution { // combination of three subpatterns- "middle, reverse, merge " // 
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // middle node 
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
 
        // partition the linkedlist
        ListNode* second = slow->next;     // second is the "head" of right part
        slow->next = nullptr;

       // reversal of linked list
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // merge alternative nodes
        second = prev;
        ListNode* first = head;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};