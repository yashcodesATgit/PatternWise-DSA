#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;   // mp == nextGreater
        stack<int> st;

        // check in nums2
        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                  nextGreater[st.top()] = num;
                  st.pop();              // popped elements become key and store num as key,value pair
            }
            st.push(num);          // push the greater num
        }
  
         // now check for nums1 elements to find
        vector<int> ans;
        for (int num : nums1)
            ans.push_back(nextGreater.count(num) ? nextGreater[num] : -1);

        return ans;

    }
};