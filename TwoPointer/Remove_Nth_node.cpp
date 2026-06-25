#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // BRUTE FORCE (2 Passes)
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        /*
         Step 1: Calculate length
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // Step 2: If head needs to be deleted
        if (len == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Step 3: Traverse to node to be deleted
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 1; i < len - n + 1; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Step 4: Delete node
        prev->next = curr->next;
        delete curr;

        return head;
        */

        
 // OPTIMAL (Fast & Slow Pointer - One Pass)
// Time Complexity: O(n)
 // Space Complexity: O(1)

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers together
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete target node
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        head = dummy->next;
        delete dummy;

        return head;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

    // Create Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    int n;
    cout << "\nEnter n: ";
    cin >> n;

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    cout << "\nLinked List after deletion:\n";
    printList(head);

    return 0;
}