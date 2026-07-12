#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n-1;    // 15 in the given example

        while(row < m && col >= 0) {

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else if(matrix[row][col] < target) row++;
        }
        return false;
    }
};