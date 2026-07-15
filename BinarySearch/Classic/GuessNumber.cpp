#include <iostream>
using namespace std;

// Hidden picked number (change this to test)
int pickedNumber = 42;

// Simulated guess API
int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

int main() {
    cout << Solution().guessNumber(100);
    return 0;
}