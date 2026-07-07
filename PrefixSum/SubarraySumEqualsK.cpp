#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        int prefixSum = 0;
        mp[0] = 1;  // unskip '0' index

        for(int num : nums) {
            prefixSum += num;

        if(mp.find(prefixSum-k) != mp.end()) {    //if exists then count increses 
            count += mp[prefixSum-k];
        }  
        mp[prefixSum]++;                  // else store in map
        }
        return count;
    }
};