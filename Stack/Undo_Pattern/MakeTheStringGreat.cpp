#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans = "";

        for(char ch : s) {
          
            if(!ans.empty() && tolower(ans.back()) == tolower(ch) && ans.back() != ch) {
                ans.pop_back();
            }
            else {
            ans.push_back(ch);
            }
      }
        return ans;
    }
};