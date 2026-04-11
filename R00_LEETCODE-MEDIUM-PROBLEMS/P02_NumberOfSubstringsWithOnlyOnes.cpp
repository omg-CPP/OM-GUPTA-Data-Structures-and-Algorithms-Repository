// Leetcode : 1513 (MEDIUM)

// Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 10^9 + 7.

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

// s = "111", how many substrings = (3*4)/2 = 6
class Solution {
public:
    int M = 1e9+7;
    int numSub(string s) {
        int n = s.length();
        long long count = 0;
        long long result = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '1') {
                count++;
            }
            else {
                result = (result + (count*(count+1))/2) % M;
                count = 0;
            }
        }
        // adding last group of 1's
        result = (result + (count*(count+1))/2) % M;
        return (int)result;
    }
};

int main()
{
    return 0;
}