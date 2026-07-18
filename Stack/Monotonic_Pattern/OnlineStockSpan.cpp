#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {    // [100, 80, 90, 120]
        int n = arr.size();
        
        vector<int> span;
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            
            while(!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();            // 120 can do this only
            }
            if(st.empty()) {
                span.push_back(i + 1);    // 120 will follow this after popping 100
            }
            else {
                span.push_back(i - st.top());     // 80,90 will follow this
            }
            st.push(i);  
        }
        
        return span;
        
    }
};