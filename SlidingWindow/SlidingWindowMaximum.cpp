#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> deque; // Indices of potential max elements in decreasing order

        for (int right = 0; right < n; right++) {
            // Remove indices out of current window
            while (!deque.empty() && deque.front() <= right - k) {
                deque.pop_front();
            }
            // Remove smaller elements from back (they can't be max)
            while (!deque.empty() && nums[deque.back()] < nums[right]) {
                deque.pop_back();
            }
            // Add current index
            deque.push_back(right);

            // Window is full size k, record max
            if (right >= k - 1) {
                res[right - k + 1] = nums[deque.front()];
            }
        }
        return res;
    }
};