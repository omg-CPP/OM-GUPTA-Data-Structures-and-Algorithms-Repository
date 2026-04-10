// Leetcode : 541 (EASY)

// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

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

// T.C. = O((N/2k) * k) = O(N)
// S.C. = O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for(int start = 0 ; start < n ; start += 2*k) {
            int i = start;
            int j = min(start+k-1,n-1);
            while(i < j) {
                swap(s[i++],s[j--]);
            }
        }
        return s;
    }
};

int main()
{
    return 0;
}