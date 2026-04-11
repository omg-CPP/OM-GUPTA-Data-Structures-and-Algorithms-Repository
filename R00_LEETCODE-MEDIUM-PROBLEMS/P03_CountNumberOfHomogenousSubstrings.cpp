// Leetcode : 1759 (MEDIUM)

// Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 10^9 + 7.
// A string is homogenous if all the characters of the string are the same.
// A substring is a contiguous sequence of characters within a string.

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
    int M = 1e9+7;
    int countHomogenous(string s) {
        int n = s.length();
        int length = 0;
        int result = 0;
        for(int i = 0 ; i < n ; i++) {
            if(i > 0 && s[i] == s[i-1]) {
                length++;
            }
            else {
                length = 1;
            }
            result = (result + length) % M;
        }
        return result;
    }
};

int main()
{
    return 0;
}

 