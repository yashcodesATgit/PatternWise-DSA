#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (int ch : s) {

            if (mp.count(ch)) {
                if (st.empty() || st.top() != mp[ch]) {
                    return false;
                }
                st.pop(); // when matches then pop so stack becomes empty and return it
                             
            } else {
                st.push(ch);
            }
        }

        return st.empty(); // means every bracket is matched
    }
};