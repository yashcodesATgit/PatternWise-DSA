#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; // word pointer
        int j = 0; // abbr pointer

        while (i < word.size() && j < abbr.size()) {

            if (isdigit(abbr[j])) {

                // Leading zero not allowed
                if (abbr[j] == '0')
                    return false;

                int num = 0;

                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                i += num; // skip characters in word
            }
            else {

                if (word[i] != abbr[j])
                    return false;

                i++;
                j++;
            }
        }

        return i == word.size() && j == abbr.size();
    }
};