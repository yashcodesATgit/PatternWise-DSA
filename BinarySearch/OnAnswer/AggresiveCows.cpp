#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &nums, int k) {
         sort(nums.begin(), nums.end());
         
         int n = nums.size();
         int low = 1, high = nums[n-1] - nums[0];
         int ans = 0;
         
         while(low <= high) {
             
             int mid = low + (high-low) / 2;
             
             if(canPlace(nums, k, mid)) {
                 ans = mid;
                 low = mid + 1;
             }
             else {
                 high = mid - 1;
             }
         }
         return ans;
    }


    bool canPlace(vector<int> &nums, int k, int gap) {
        int cowCount = 1;             
        int lastCow = nums[0];              // first cow at index "0"
        
        for(int i=1; i<nums.size(); i++) {
       
        if((nums[i] - lastCow) >= gap) {   // maximize the min. gap    
               cowCount++;
               lastCow = nums[i];       // now second cow becomes latest/lastCow    
          }
        }
        return cowCount >= k;           // return minimum cows that can be placed 
    }
};    