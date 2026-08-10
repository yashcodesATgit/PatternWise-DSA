#include <vector>
#include <bits/stdc++.h>
using namespace std;

// D.P LOGIC - (n * m) TIME COMPLEXITY //
// MEMOIZATION LOGIC //  SIMILAR TO "UNIQUE PATHS I"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));  // dp matrix of m*n

        return countPaths(m - 1, n - 1, obstacleGrid, dp);
    }

    int countPaths(int row, int col,
                   vector<vector<int>>& obstacleGrid,
                   vector<vector<int>>& dp) {

        if (row < 0 || col < 0) {    // outside the grid
            return 0;
        }

        if (obstacleGrid[row][col] == 1) {  // obstacle cell
            return 0;
        }

        if (row == 0 && col == 0) {      // starting cell
            return 1;
        }

        if (dp[row][col] != -1) {     // if already calculated then return in dp
            return dp[row][col];
        }

        // store the result in dp to return it later
        dp[row][col] = countPaths(row - 1, col, obstacleGrid, dp)
                     + countPaths(row, col - 1, obstacleGrid, dp);

        return dp[row][col];
    }
};


/* // RECURSIVE APPROACH - (2^n) TIME COMPLEXITY ------> TLE //
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (i >= m || j >= n) {       // Outside the grid
            return 0;
        }
        if (obstacleGrid[i][j] == 1) {  // Obstacle grid
            return 0;
        } 
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
       
        return solve(i + 1, j, obstacleGrid) +
               solve(i, j + 1, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(0, 0, obstacleGrid);
    }
};
*/