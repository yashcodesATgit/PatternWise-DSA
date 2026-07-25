#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string s;

        for(char ch : num) {
         
           while(k > 0 && !s.empty() && s.back() > ch) {
           s.pop_back();
            k--;
        }
        s.push_back(ch);
        }

        s.resize(s.size() - k);

        // remove leading zeroes to get minimum answer
        int i = 0;

        while(i < s.size() && s[i] == '0') {        // "000123"
            i++;                                    // i -----> 3
        }

        string ans = s.substr(i);       // "i" points to the index where valid digit is present (index-3)
       
        return ans.empty() ? "0" : ans;

    }
};