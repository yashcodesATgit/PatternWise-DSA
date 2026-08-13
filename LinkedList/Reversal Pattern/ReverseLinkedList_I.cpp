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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
           ListNode* next = curr->next;

      // now reverse the pointer direction
           curr->next = prev;
           prev = curr;   // update prev
           curr = next;   // update curr
        }

        return prev;
    }
};