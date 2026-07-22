#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
         queue<int> q1, q2;
    MyStack() {}

    void push(int x) {
        q1.push(x);
    }
 
    int pop() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int value = q1.front();
        q1.pop();
        q1 = q2;       // always use q2 for taking new elements dont operate here
        q2 = queue<int> ();
        return value;
    }
    
    int top() {
         while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int value = q1.front();
        q2.push(q1.front());
        q1.pop();
        q1 = q2;       // always use q2 for taking new elements dont operate here
        q2 = queue<int> ();
        return value;
    }
    
    bool empty() {
        return q1.empty();
    }
};



