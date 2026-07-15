#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canAllocate(vector<int> &arr, int k, int maxPages) {
        int students = 1;
        int pagesSum = 0;

        for (int pages : arr) {

            if (pages > maxPages)  return false;

            if (pagesSum + pages <= maxPages) {
                pagesSum += pages;
            } 
            else {
                students++;
                pagesSum = pages;
            }

            if (students > k)      return false;
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size())
            return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAllocate(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};