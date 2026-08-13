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
    int pairSum(ListNode* head) {
        // Find middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;        // slow is the mid

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Calculate maximum twin sum
        int maxSum = 0;

        ListNode* first = head;
        ListNode* second = prev;       // prev is head-2 of second half

        while (second != nullptr){
            maxSum = max(maxSum, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};