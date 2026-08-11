#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) { // constructor
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p = headA;
        ListNode* q = headB;

       // means when they become nulll then send it to opposite head and start from there
        while (p != q) {
            p = (p == NULL) ? headB : p->next;
            q = (q == NULL) ? headA : q->next;
        }

        return p;
    }
};