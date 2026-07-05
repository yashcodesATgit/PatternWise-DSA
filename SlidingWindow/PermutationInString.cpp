#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0); // freq array stores better than hashmaps when needed.

        for (char ch : s1) {
            freq1[ch - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            freq2[s2[right] - 'a']++;

            if (right - left + 1 > s1.size()) {     // Maintain window size equal to s1.size()
                freq2[s2[left] - 'a']--;
                left++;
            }
            if (right - left + 1 == s1.size()) {    // Compare frequency arrays
                if (freq1 == freq2) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
// brute force :-
use two loops, store frequencies of s1 string in hashmap 1 using foreach loop. And compare with second hashmap made using two for loops classic sliding window brute force.

            if (mpp == mp) {
                return true;
 */