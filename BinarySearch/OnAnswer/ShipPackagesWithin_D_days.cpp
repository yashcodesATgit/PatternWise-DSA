#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int day = 1;          // Start with the first day
        int currWeight = 0;   // Current load on the ship

        for (int weight : weights) {

            if (currWeight + weight > capacity) {
                currWeight += weight;
            } else {
                day++;         // extra capacity passes to next day
                currWeight = weight;
            }
        }
        return day <= days;         
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;  // Initialize answer with the maximum possible capacity.

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid; 
                high = mid - 1;   // search for more lower capacity
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};