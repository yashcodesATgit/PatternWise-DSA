#include <vector>
#include <bits/stdc++.h>
using namespace std;

/* 
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        st.push(0);        // push one "zero" by default

        for(char ch : s) {

            if(ch == '(') {
                st.push(0);  // found open bracket ----->  push "zero"
            }
            else {
                int value = st.top();  st.pop();
                int score = max(2 * value, 1);
                int top = st.top();  st.pop();
                
                st.push(score + top);
            }
        }
        return st.top();
    }
};
*/

                   // MORE OPTIMISED IN TERMS OF SC- O(1) //

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;          // inccrease count only for "opening" bracket
            } else {
                count--;
                if (s[i-1] == '(')
                 score += 1 << count;  // left shift by "count", 1 << count == "2" to the power "count"
            }
        }

        return score;
    }
};
