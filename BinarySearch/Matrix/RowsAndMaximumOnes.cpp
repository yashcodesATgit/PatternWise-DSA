#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxRow = 0;
        int maxOnes = 0;

        for (int i = 0; i < mat.size(); i++) {
            int ones = 0;
            for (int x : mat[i]) {
                ones += x;
            }

            if (ones > maxOnes) {
                maxOnes = ones;
                maxRow = i;
            }
        }

        return {maxRow, maxOnes};
    }
};



// IF MATRIX WAS SORTED THEN BEST APPROACH WILL BE - "BINARY SEARCH" 

/*
class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxRow = -1;
        int maxOnes = 0;

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            int firstOne = m;

            while (low <= high) {                // Binary search to find first occurrence of 1
                int mid = low + (high - low) / 2;

                if (mat[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            int ones = m - firstOne;

            if (ones > maxOnes) {
                maxOnes = ones;
                maxRow = i;
            }
        }

        return maxRow;
    }
};
*/