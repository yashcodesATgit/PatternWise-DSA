#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSum = 0;

        for(int i=0; i<k; i++) {    // checks first window of 'k length
            windowSum += nums[i];
        }
        int maxSum = windowSum;

        for(int i=k; i<n; i++) {        // loop for second window and so on.......
            windowSum += nums[i];
            windowSum -= nums[i-k];

        maxSum = max(maxSum, windowSum);   
        }

        return maxSum;
    }
};