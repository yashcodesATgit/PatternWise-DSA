#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size();
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++;

            // If we have more than 2 types of fruits, shrink the window from the left
            while (mp.size() > 2) {
                mp[fruits[left]]--;
                
                // If the count of the fruit at 'left' becomes 0, remove it from the map
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};