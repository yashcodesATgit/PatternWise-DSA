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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {              // start a newptr from head and match it with slow
                ListNode* newptr = head;

                while(newptr != slow) {    // move with same speed until matches
                    slow = slow->next;
                    newptr = newptr->next;
                }
                return newptr;
            }
        }

        return nullptr;
    }
};