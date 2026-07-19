#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;                      // string as a stack

        for (char ch : s) {
            if (!ans.empty() && ans.back() == ch)        // ans.back() === stack.top()
                ans.pop_back();
            else
                ans.push_back(ch);
        }

        return ans;
    }
};
