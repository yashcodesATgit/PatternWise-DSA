#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;      // [2,3,4,7,11] , k = 5

        while (left <= right) {
            int mid = (left + right) / 2;        // mid = 2 or arr[mid] = 4

            if (arr[mid] - (mid + 1) < k)  //  checks Missing numbers before arr[mid] => 4 - 3 < 5
                left = mid + 1;            // search right half
            else
                right = mid - 1;
        }

        return left + k;               
    }
};