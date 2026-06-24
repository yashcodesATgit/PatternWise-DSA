#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

 for(int f = 0; f < n; f++) { // skip duplicates of fixed element
 
     if(f > 0 && nums[f] == nums[f-1])
        continue;

         int i = f + 1;
         int j = n - 1;
// main logic
         while(i < j) {

            int sum = nums[f] + nums[i] + nums[j];

            if(sum < 0) {
                    i++;
                }
            else if(sum > 0) {
                    j--;
                }
              else {
                 ans.push_back({
                        nums[f],
                        nums[i],
                        nums[j]
                    });
                    i++;
                    j--;

     while(i < j && nums[i] == nums[i-1]) { // skip duplicates of i element
             i++; 
        }
      }
    }
 }
        return ans;
        }
};