#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;

        int high = 0;
        for (int pile : piles) {
            if (pile > high) {
                high = pile;
            }
        }

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = 0;

            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;        // mid works, remember it
                high = mid - 1;   // try a smaller speed
            }
            else {
                low = mid + 1;    // speed too slow
            }
        }

        return ans;
    }
};