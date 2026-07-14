#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //Base case
        if((long long) m * k > bloomDay.size()) return -1;

        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

         while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canMake(bloomDay, m, k , mid)) {
                ans = mid;
                high = mid - 1;    // search for more minimum
            }
            else {
                low = mid + 1;
            }
         }
         return ans;
    }

   bool canMake(vector<int>& bloomDay, int m, int k, int day) {
    int flowerCount = 0, bouquetsCount = 0;

    for (int bloom : bloomDay) {
        if (bloom <= day) {       // bloom cannot be more than the day
            flowerCount++;

            if (flowerCount == k) { // ==  required consecutive flowers 
                bouquetsCount++;
                flowerCount = 0;    // reset for next bloom
            }
        } 
        else {
            //  flower hasn't bloomed yet, so consecutive count resets to "0".
            flowerCount = 0;
        }
    }
    return bouquetsCount >= m;
}
};