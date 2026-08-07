#include <vector>
#include <bits/stdc++.h>
using namespace std;

// D.P LOGIC - (n * m) TIME COMPLEXITY //
// MEMOIZATION LOGIC //
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));  // dp matrix of m*n

        return countPaths(m - 1, n - 1, dp);
    }

    int countPaths(int row, int col, vector<vector<int>>& dp) {

        if (row == 0 || col == 0) {
            return 1;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        // store the result in dp to return it later
        dp[row][col] = countPaths(row - 1, col, dp)
                     + countPaths(row, col - 1, dp);

        return dp[row][col];
    }
};

/*
// RECURSION LOGIC - (2^n) TIME COMPLEXITY ------> TLE //
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        return countPaths(m-1, n-1);
    }

    int countPaths(int row, int col) {
        if(row == 0 || col == 0) {
            return 1;       // single path to traverse
        }

        return countPaths(row-1, col) + countPaths(row, col-1); // for each block , its upper and left block
    }
};
*/
