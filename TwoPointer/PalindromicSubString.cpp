#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Expand(string &s, int left, int right) {
        int Count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            Count++;
            left--;
            right++;
        }
        return Count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int Count = 0;

        for(int i = 0; i<n; i++) {
           Count += Expand(s, i, i);    // odd
           Count += Expand(s, i, i+1);  // even

        }
        return Count;
    }
};