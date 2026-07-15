#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {     //  [1,2,3,1]
        int left = 0;
        int right = nums.size()-1;

        while(left < right) {
            int mid = left + (right - left + 1) / 2; // Upper mid to avoid infinite loop when left = mid

            if(nums[mid] > nums[mid-1]) {     // peak will be in right 
                    left = mid;
            } 
            else {
                right = mid-1;
            }
        }
        return left;    // or right
    }
};