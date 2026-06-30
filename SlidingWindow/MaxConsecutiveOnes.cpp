#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_count = 0;
        int max_count = 0;

        for (int num : nums) {
            if (num == 1) {
                curr_count++;
                max_count = max(max_count, curr_count);
            } else {
                curr_count = 0;
            }
        }
        return max_count;
    }
};