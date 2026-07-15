#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {  // core logic - if pair exists then search in right half
        int low = 0, high = nums.size() - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 0) {  // even index
                if (nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {             // odd index
                if (nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return nums[low];
    }
};