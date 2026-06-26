#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        int left = 0;
        int right = num.size() - 1;

        while (left <= right) {
            if (mp.find(num[left]) == mp.end())   // left doesnt exist in map 
                return false;
            if (mp[num[left]] != num[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};