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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        // Find middle node 
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half (from mid to last node)
        ListNode *prev = nullptr;
        ListNode *curr = slow;         // slow points to the mid node.

        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Compare both halves
        while (prev != nullptr) {               // prev is same as head-2 of second-half
            if (head->val != prev->val)
                return false;

            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};