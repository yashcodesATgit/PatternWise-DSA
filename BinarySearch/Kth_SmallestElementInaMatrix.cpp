#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countLessOrEqual(matrix, mid);
            
            if (count < k)
                low = mid + 1;      // Need larger numbers
            else
                high = mid - 1;     // Try a smaller answer
        }
        return low;
    }
    
    int countLessOrEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        int count = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                
                count += row + 1;   // All elements above are also <= target
                col++;              // Move right
            } 
            else {
                row--;              // Move up
            }
        }
        return count;
    }
}; 