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
        ListNode* cur = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {

       // move curr->next not current as more duplicates can be found
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};