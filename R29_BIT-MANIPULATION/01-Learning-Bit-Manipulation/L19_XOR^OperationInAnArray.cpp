// Leetcode : 1486 (EASY)

// You are given an integer n and an integer start.
// Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.
// Return the bitwise XOR of all elements of nums.

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
    int xorOperation(int n, int start) {
        int xorr = 0;
        for(int i = 0 ; i < n ; i++) {
            xorr = xorr ^ (start + 2*i);
        }
        return xorr;
    }
};

// why xorr = 0 ?
// property: 
// 1. a ^ a = 0
// 2. a ^ 0 = a
// n = 5, start = 0
// 0, 2, 4, 6, 8

int main()
{   
    return 0;
}