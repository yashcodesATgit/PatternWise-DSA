#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i =1; i<n ; i++) {

            if(nums[i] < nums[i-1]) {   // rotated array has one position of order change
                count++;
            }
        }
        if(nums[n-1] > nums[0]) {      // check for sorted array
            count++;
        }

        return count <= 1;        // if count > 1 then it cannot be sorted but rotated
    }
};