#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, smap;
        for (char ch : t) tmap[ch]++;

        int left = 0, count = 0;
        int minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            smap[s[right]]++;

            if (tmap.count(s[right]) && smap[s[right]] <= tmap[s[right]]) {
                count++;
            }

            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                smap[s[left]]--;
                if (tmap.count(s[left]) && smap[s[left]] < tmap[s[left]]) {
                    count--; //was a required character and removing it dropped its count below what's needed. If so, the window is no longer valid
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};