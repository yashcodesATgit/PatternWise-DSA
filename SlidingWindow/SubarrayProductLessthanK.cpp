#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <=1) return 0;
      
      int n = nums.size();
      int left = 0;
      int count = 0;
      int prod = 1;

      for(int right=0; right<n; right++) {
        prod *= nums[right];
      
      while(prod >= k) {
        prod /= nums[left];
        left++;
      }
      count += right-left+1;
    }
    return count;
    }      
};  