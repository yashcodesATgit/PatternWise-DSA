#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            while (!st.empty() && st.top() > 0 && a < 0 && st.top() < -a) {
                st.pop(); // positive asteroid explodes
            }

            if (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() == -a) {
                    st.pop(); // both explode
                }
                // else st.top() > -a, so current asteroid explodes
            } else {
                st.push(a); // no collision
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};