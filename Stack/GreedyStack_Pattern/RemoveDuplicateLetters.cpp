  // same as "smallestSubsequence" problem // 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        stack<char> st;
        vector<bool> visited(26, false);
        vector<int> lastIndex(26);

        // Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (visited[ch - 'a'])    // Skip if already in stack
                continue;

   // Remove larger characters if they have more occurences later to maintain lexical order
            while (!st.empty() &&
                   st.top() > ch &&
                   lastIndex[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        string ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};