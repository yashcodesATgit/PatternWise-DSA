#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;         // s = " ab#cd##f#g "
        int j = t.size() - 1;         // t = " ab#g " 
        int skipS = 0, skipT = 0;               

     while (i >= 0 || j >= 0) {

        while (i >= 0) {
            if (s[i] == '#') {
                    skipS++;
                    i--;
                }
            else if (skipS > 0) {  // skipS = 2 after skipping 'f'
                    skipS--;
                    i--;         // c and d are skipped
                }
            else break;
            }

            while (j >= 0) {        // same logic as skipS
                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else break;
            }

            if ((i >= 0) != (j >= 0)) return false;   // when any char left after iteration

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;       // when char does not matches 
            }

            i--;
            j--;
        }
        return true;
    }
};