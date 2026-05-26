// Leetcode : 2309 (EASY)

// Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

// An English letter b is greater than another letter a if b appears after a in the English alphabet.

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cmath>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        // mark occurrences
        for(char& ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                lower[ch-'a'] = true;
            }
            else if(ch >= 'A' && ch <= 'Z') {
                upper[ch-'A'] = true;
            }
        }

        // check from greatest letter to smallest
        for(int i = 25 ; i >= 0 ; i--) {
            if(lower[i] && upper[i]) {
                char ans = 'A' + i;
                return string(1,ans);
            }
        }
        return "";
    }
};

int main()
{
    return 0;
}