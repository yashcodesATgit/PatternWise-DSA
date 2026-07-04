#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;  // count last index instead of frequency
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            if (lastIndex.count(s[right])) {        // if right pointer element comes again
                left = max(left, lastIndex[s[right]] + 1); // move the index instead of frequency
            }

            lastIndex[s[right]] = right;        // update the right pointer
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
}; 

/*
// slightly less optimised approach 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int left=0, maxLen=0;

        for(int right=0; right<n; right++) {
            mp[s[right]]++;

           while(mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
           } 
           maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
*/ 