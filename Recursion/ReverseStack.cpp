#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseStack(stack<int>& s) {
        if (s.empty())
            return;

        int x = s.top();
        s.pop();

        reverseStack(s);

        insertBottom(s, x);
    }

    void insertBottom(stack<int>& s, int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }

        int y = s.top();
        s.pop();

        insertBottom(s, x);

        s.push(y);
    }
};