#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& stations, int k, double maxAllowedDistance) {
        int requiredStations = 0;
        int lastStation = stations[0];

        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - lastStation;

            requiredStations += ceil(gap / maxAllowedDistance) - 1;

            lastStation = stations[i];
        }

        return requiredStations <= k;
    }

    double minMaxDist(vector<int>& stations, int k) {
        double low = 0.0;
        double high = stations.back() - stations.front();
        double ans = high;

        while (high - low > 1e-6) {
            double mid = low + (high - low) / 2.0;

            if (check(stations, k, mid)) {
                ans = mid;      // Current feasible answer
                high = mid;
            } else {
                low = mid;
            }
        }

        return ans;
    }
};