#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int DivideBy(vector<int>& nums, int threshold, int div) {
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {

            sum += ceil((double)nums[i] / (double)div);
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high) {

            int mid = low + (high - low ) / 2;

            if(DivideBy(nums, threshold, mid)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};