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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {  // jumps Kth node 'k' times
                kth = kth->next;
            }

            if (!kth) break;    // if "less than k nodes" present do nothing

            ListNode* groupNext = kth->next;
            // Reverse the group now
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;    // head

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Reconnect the reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};