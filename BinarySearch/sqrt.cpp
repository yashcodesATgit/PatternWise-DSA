#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;

        int left = 1, right = x/2;     // square root will always be <= x/2 

        while(left <= right) {
            long long mid = left + (right - left) / 2;
            long long sqrt = mid * mid;
            if(sqrt == x) return mid;
            if(sqrt < x) left = mid + 1;
            if(sqrt > x) right = mid - 1;
        }
        return right;
    }
};