#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();

        if (m > n) return ans;

        vector<int> pCount(26, 0), sCount(26, 0);

        // Count characters of p and first window of s
        for (int i = 0; i < m; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        // Check first window
        if (pCount == sCount)
            ans.push_back(0);

        // Slide the window
        for (int i = m; i < n; i++) {
            sCount[s[i] - 'a']++;        // Add new character
            sCount[s[i - m] - 'a']--;    // Remove old character

            if (pCount == sCount)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};