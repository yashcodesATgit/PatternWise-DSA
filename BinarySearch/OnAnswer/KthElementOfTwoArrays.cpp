#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();

        if (n > m)
            return kthElement(nums2, nums1, k);   // Search smaller array

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int mid = (low + high) / 2;
            int other = k - mid;                  // Elements from nums2

            int l1 = (mid == 0) ? INT_MIN : nums1[mid - 1];  // left half of arr-1
            int r1 = (mid == n) ? INT_MAX : nums1[mid];      // right half of arr-1

            int l2 = (other == 0) ? INT_MIN : nums2[other - 1];
            int r2 = (other == m) ? INT_MAX : nums2[other];

            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);

            if (l1 > r2)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};