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

class Solution { // O(n + m) time complexity //
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    stack<int> s1, s2;

    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }

    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0;

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    while (!s1.empty() || !s2.empty() || carry) {

        int sum = carry;

        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }

        carry = sum / 10;

        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    // Reverse result at the end as stack gives us LIFO digits // 
    return reverse(dummy->next);
} 

    ListNode* reverse(ListNode* head) { 
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

/*
class Solution {        // O(4n) time complexity //
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);

        // Same logic as "Add Two Numbers I"problem
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return reverse(dummy->next);
    }
};
*/