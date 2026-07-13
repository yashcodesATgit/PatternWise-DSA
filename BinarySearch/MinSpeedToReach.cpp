#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canreach(vector<int>& dist, double hour, int speed) {
        double time = 0.0;

        for(int i=0; i<dist.size(); i++) {
          
            double t = (double) dist[i] / speed;

           if(i != dist.size()-1) {
            time += ceil(t);
           }
           else {
            time += t;
           }  
        }
        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
         int low = 1, high = 1e7; // high = 10 (to the power) 7
         int ans = -1;

         while(low <= high) {
            
            int mid = low + (high-low) / 2;

            if(canreach(dist,hour,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
         }
         return ans;
    }
};