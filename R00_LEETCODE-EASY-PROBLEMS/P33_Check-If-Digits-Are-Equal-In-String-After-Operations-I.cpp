// Leetcode : 3461 (EASY)

// You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

// For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
// Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
// Return true if the final two digits in s are the same; otherwise, return false.

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

// T.C. = O(N^2)
// S.C. = O(N) 
class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> v;
        for(char& ch : s) v.push_back(ch-'0');
        while(v.size() > 2) {
            vector<int> new_v;
            for(int i = 0 ; i < v.size()-1 ; i++) {
                new_v.push_back((v[i] + v[i+1]) % 10);
            }
            // over-ride
            v = new_v;
        }
        return v[0] == v[1];
    }
};

int main()
{
    return 0;
}