// Leetcode : 3043 (MEDIUM)

// You are given two arrays with positive integers arr1 and arr2.

// A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

// A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.

// You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

// Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        // Store all prefixes of arr1 numbers
        for(int& num : arr1) {
            string s = to_string(num);
            string prefix = "";
            for(char& ch : s) {
                prefix += ch;
                prefixes.insert(prefix);
            }
        }

        int maxLen = 0;
        // Check prefixes of arr2 numbers
        for(int& num : arr2) {
            string s = to_string(num);
            string prefix = "";
            for(char& ch : s) {
                prefix += ch;
                if(prefixes.count(prefix)) {
                    maxLen = max(maxLen, (int)prefix.length());
                }
            }
        }
        return maxLen;
    }
};

// string s = "hello";
// cout << s.length();          // returns size_t
// cout << (int)s.length();     // converted to int

int main()
{
    return 0;
}