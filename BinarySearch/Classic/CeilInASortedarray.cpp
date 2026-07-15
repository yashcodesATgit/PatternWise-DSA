#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int findCeil(vector<int>& nums, int x) {
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;          // No floor found yet

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= x) {
            ans = mid;      // nums[mid] can be the ceil
            right = mid - 1; // smaller than mid but >= x can still exist
        }
        else {
            left = mid + 1; // Need a larger value
        }
    }

    return ans;
   }
};
