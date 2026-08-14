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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, nullptr);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap pair of nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to next pair
            prev = first;
        }

        return dummy.next;
    }
};

