#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char sign = '+';  // sign before the very first number

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // if current char is an operator, or we reached end of string
            if((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if(sign == '+') {
                    st.push(num);
                } else if(sign == '-') {
                    st.push(-num);
                } else if(sign == '*') {
                    int prev = st.top(); st.pop();
                    st.push(prev * num);
                } else if(sign == '/') {
                    int prev = st.top(); st.pop();
                    st.push(prev / num);
                }
                sign = c;   // update sign for next number
                num = 0;    // reset number
            }
        }

        int result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};