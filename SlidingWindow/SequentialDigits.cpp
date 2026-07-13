#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       string s = "123456789";
       vector<int> ans;

        for(int strlen = 2; strlen <= 9; strlen++) {  // according to the constraints
         for(int start = 0; start <= s.size() - strlen; start++) { // to include only valid substrings
                
             int digit = stoi(s.substr(start, strlen));  // "stoi" converts string into integer

             if(digit >= low && digit <= high) {
                    ans.push_back(digit);
                }
            }
        }
         return ans;
    }
};