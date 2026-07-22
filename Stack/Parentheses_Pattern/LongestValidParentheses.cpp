#include <vector>
#include <bits/stdc++.h>
using namespace std;

// MOST OPTIMISED //

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0;
        int n = s.size();

        // Left to right
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, 2 * right);
            else if (right > left) {   
                left = right = 0;
            }
        }

        left = right = 0;

        // Right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')')
                right++;
            else
                left++;

            if (left == right)
                ans = max(ans, 2 * left);
            else if (left > right) {   
                left = right = 0;
            }
        }

        return ans;
    }
};
 
/*
// BETTER //

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int n = s.size();
        int maxLen = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
               st.push(i);
            }
            else {
                st.pop();    
                if(st.empty()) {
                    st.push(i);
                }
            else {
                maxLen = max(maxLen, i - st.top());
            }
        }
     }
        return maxLen; 
    }
};


// BRUTE FORCE //

class Solution {
public:

    bool isValid(string s) {
        int count = 0;

        for(char ch : s) {
            if(ch == '(') {
                count++;
            }
            else {
                count--;
                if(count < 0) return false;
            }
        }
        return count == 0;
    }

    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j += 2) {

                if (isValid(s.substr(i, j - i + 1))) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

*/