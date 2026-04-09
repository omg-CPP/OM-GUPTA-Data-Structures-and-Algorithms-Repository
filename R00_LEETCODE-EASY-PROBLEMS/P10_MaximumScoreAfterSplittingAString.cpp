// Leetcode : 1422 (EASY)

// Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

// The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

// see this test case :: you will get a hint
// Input: s = "011101"
// Output: 5 
// Explanation: 
// All possible ways of splitting s into two non-empty substrings are:
// left = "0" and right = "11101", score = 1 + 4 = 5 
// left = "01" and right = "1101", score = 1 + 3 = 4 
// left = "011" and right = "101", score = 1 + 2 = 3 
// left = "0111" and right = "01", score = 1 + 1 = 2 
// left = "01110" and right = "1", score = 2 + 1 = 3

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

// T.C. = O(N) + O(N) = O(N)
class Solution {
public:
    int maxScore(string s) {
        int Zeros = 0;
        int Ones = 0;
        for(auto& ch : s) {
            if(ch == '0') Zeros++;
            else Ones++;
        }
        int maxScore = 0;
        int countLeftZeros = 0;
        int countLeftOnes = 0;
        if(s[0] == '0') countLeftZeros++;
        else countLeftOnes++;
        // putting boundart from idx = 1
        for(int i = 1 ; i < s.length() ; i++) {
            maxScore = max(maxScore,countLeftZeros + (Ones-countLeftOnes));
            // update for next step
            if(s[i] == '0') countLeftZeros++;
            else countLeftOnes++;
        }
        return maxScore;
    }
};

int main()
{
    return 0;
}