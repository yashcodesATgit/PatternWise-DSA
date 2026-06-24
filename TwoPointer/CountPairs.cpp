#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        int count = 0;

        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum < target){
                count += (j-i); // if extremes are less than tar then lower extreme are also the same.
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};