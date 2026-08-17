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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            bool duplicate = false;

            while (curr->next && curr->val == curr->next->val) {
                duplicate = true;
                curr = curr->next;
            }

            if (duplicate) {
                prev->next = curr->next; //curr points to the last duplicate of the group.
            } else {
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};