#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long currMin;

    void push(int x) {
        if (st.empty()) {
            currMin = x;
            st.push(x);
        } else if (x >= currMin) {
            st.push(x);
        } else {
            st.push(2LL * x - currMin);
            currMin = x;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < currMin) {
            currMin = 2LL * currMin - st.top();
        }

        st.pop();
    }

    int top() {
        if (st.top() >= currMin)
            return st.top();

        return currMin;
    }

    int getMin() {
        return currMin;
    }
};


/*

// BRUTE FORCE ------> SC = O(N) //

class MinStack {
public:
    stack<int> St;      // Stores all elements
    stack<int> minSt;   // Stores minimum till each position

    MinStack() {}

    void push(int x) {
        St.push(x);

        if (minSt.empty()) {      
            minSt.push(x);                     // First element is the minimum
        } else {
            minSt.push(min(x, minSt.top()));  // Store current minimum
        }
    }

    void pop() {
        if (!St.empty()) {
            St.pop();       // Remove top element
            minSt.pop();    // Remove corresponding minimum also
        }
    }

    int top() {
        if (St.empty()) return -1;

        return St.top();    
    }

    int getMin() {
        if (St.empty()) return -1;

        return minSt.top(); 
    }
};
*/

