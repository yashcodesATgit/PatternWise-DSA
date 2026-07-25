#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> st;
    vector<int> inc;    // we will perform increment operations here
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (st.size() == maxSize)
            return;

        st.push_back(x);
        inc.push_back(0);     // initialise inc array with '0'
    }

    int pop() {
        if (st.empty())
            return -1;

        int i = st.size() - 1;          // top of array/stack
        int ans = st.back() + inc[i];

        if (i > 0)
            inc[i - 1] += inc[i]; // pass the value of "i to i-1" in inc array one at a time

        st.pop_back();
        inc.pop_back();

        return ans;
    }

    void increment(int k, int val) {
        int i = min(k, (int)st.size()) - 1;
        if (i >= 0)
            inc[i] += val;
    }
};