#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i<nums.size();i++) {
            
            int lookingFor = target - nums[i];

            if(mp.find(lookingFor) != mp.end()) {  // key pair exists
                return {mp[lookingFor], i};
            }

            mp[nums[i]] = i;   // stores nums [i] with its index
        }
                return {};

    }
};