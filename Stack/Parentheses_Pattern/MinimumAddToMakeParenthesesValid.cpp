#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;      // TC- O(n)  and  SC- O(n)---  we can reduce SC by not using stack
        int closing = 0;

        for(int ch : s) {

            if(ch == '(') {
                st.push(ch);
            }
            else if(!st.empty()) {
                st.pop();
            }
            else {
                closing++;
            }
        }

        return closing + st.size();
    }
};
*/


               // MOST OPTIMISED VERSION WITH SC == O(1)  // 

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int closing = 0;
        int opening = 0;

        for(char ch  :s) {

            if(ch == '(') {
                opening++;
            }
            else if(opening > 0) {
                opening--;
            }
            else {
                closing++;
            }
        }
        
        return opening + closing;
    }
};