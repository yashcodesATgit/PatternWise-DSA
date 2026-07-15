#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findFirst(vector<int>& nums, int target) {
         int left = 0, right = nums.size() - 1, ans = -1;

         while(left <= right) {
            
            int mid = left + (right - left) / 2;

        if(nums[mid] == target) ans = mid , right = mid - 1; // there can be more occurence in left
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1; 
         }
         return ans;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = -1;

         while(left <= right) {
           
            int mid = left + (right - left) / 2;
            
        if(nums[mid] == target) ans = mid , left = mid + 1; // there can be more occurence in right
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1; 
         }
         return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};