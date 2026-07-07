#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {     // nums[] = [2,3,4,5] 
      int n = nums.size();
      vector<int> prod(n);
      prod[0] = 1;  // leftmost product of '0'th index is 1 only.

      for(int i=1; i<n; i++) {
        prod[i] = prod[i-1] * nums[i-1];    // left product  = [1,2,6,24]
      }
      
      int rightProd = 1;
      for(int i=n-1; i>=0; i--) {
        prod[i] *= rightProd;             // right product  = [60,20,5,1]  * leftProduct
        rightProd *= nums[i];              
      }
          return prod;
    }
  };