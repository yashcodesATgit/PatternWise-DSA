#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefixSum = 0;
        for(int i=0; i<n; i++) {
            prefixSum += nums[i];

            int remainder = prefixSum % k;  // subtract its index from original index to verify the length
            if(mp.find(remainder) != mp.end()) {

                if(i - mp[remainder] >= 2) {   // good array condition
                    return true;
                }

            }
            else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};