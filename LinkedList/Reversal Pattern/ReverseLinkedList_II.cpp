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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);  // if left == 1, we can have atleast one node before

        // prev = one node before the part we want to reverse
        // Move prev to the node just before 'left'
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr = first node of the section we want to reverse
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};