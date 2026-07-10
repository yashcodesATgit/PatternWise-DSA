#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {          // [6,7,3,4,5]
        int left = 0;
        int right = nums.size()-1;

        while(left < right) {
            int mid = left + (right-left) / 2;

          if(nums[mid] <= nums[right]) { // right sorted , so minimum will be in left sorted
              right = mid;              // mid can be the answer also so right won't be mid-1
          }  
          else {
            left = mid+1;
          }
        }
        return nums[left];   // or nums[right]
    }
};