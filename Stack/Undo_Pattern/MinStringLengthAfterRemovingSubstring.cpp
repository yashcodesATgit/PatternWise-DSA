#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        string ans;

        for (char ch : s) {
            if (!ans.empty()) {
                char last = ans.back();      // similar to --->  last == top element of stack

                if ((last == 'A' && ch == 'B') ||
                    (last == 'C' && ch == 'D')) {
                    ans.pop_back();
                    continue;
                }
            }
            ans.push_back(ch);
        }

        return ans.size();
    }
};