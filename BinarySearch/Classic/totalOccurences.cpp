#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countFreq(vector<int>& nums, int target) {

        int first = findFirst(nums, target);
        if (first == -1) return 0;

        int last = findLast(nums, target);

        return last - first + 1;
    }

    int findFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};