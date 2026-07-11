// OPTIMISED-APPROACH
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
};


// BRUTE-FORCE APPROACH
/*   
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {    // for k = 3
        // Brute Force approach
         int n = nums.size();
        
        for(int j = 0; j < k; j++) {    // runs for k time,   [1,2,3,4,5,6,7]
            int temp = nums[n-1];       // temp = 7 

            for(int i = n-2; i >= 0; i--) {  // run from 6 to 1
                nums[i+1] = nums[i];         
            }
            nums[0] = temp;             // [5,6,7,1,2,3,4]
        }
    }
};
*/   