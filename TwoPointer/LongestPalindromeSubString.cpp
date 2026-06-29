/*                        // Brute - Force approach
class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])  return false;
            
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string result = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if ((j - i + 1) > result.length()) {
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
};
*/

                               // Optimised approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helperString(string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            int odd = helperString(s, i, i);
            int even = helperString(s, i, i + 1);
            int length = max(odd, even);

            if (length > end - start + 1) {
                start = i - (length - 1) / 2;
                end = i + length / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};