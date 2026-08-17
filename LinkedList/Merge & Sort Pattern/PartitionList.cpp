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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallDummy = new ListNode(0);    // keep track of smaller than x
        ListNode* largeDummy = new ListNode(0);    // keep track of larger or equal to x 

        ListNode* small = smallDummy;  // moving node
        ListNode* large = largeDummy;  // moving node

        ListNode* curr = head;

        while(curr != nullptr) {
            if(curr->val < x) {
                small->next = curr;
                small = small->next;
            }
            else {
                large->next = curr;
                large = large->next;
            }
            curr = curr->next;
        }

        small->next = largeDummy->next;  // connect small and large
        large->next = nullptr;

        return smallDummy->next;
    }
};