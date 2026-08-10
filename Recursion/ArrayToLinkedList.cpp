#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
    
    Node* build(vector<int>& arr, int i) {
        if (i == arr.size())
            return nullptr;

        Node* head = new Node(arr[i]);
        head->next = build(arr, i + 1);

        return head;
    }

public:
    Node* arrayToList(vector<int>& arr) {
        return build(arr, 0);
    }
};