// Leetcode : 2078 (MEDIUM)

// There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

// Return the maximum distance between two houses with different colors.

// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

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
    // T.C. = O(2N)
    // S.C. = O(1)
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxD = 0;
        int left = 0;
        int right = n-1;
        // calculating max distance from left end
        while(right > 0 && colors[right] == colors[0]) {
            right--;
        }
        maxD = max(maxD, abs(right - left));
        // calculating max distance from right end
        right = n-1;
        while(left < n && colors[left] == colors[n-1]) {
            left++;
        }
        maxD = max(maxD, abs(right - left));
        return maxD;
    }

    // optimised: one pass
    // T.C. = O(N)
    // S.C. = O(1)
    int maxDistance_OnePassSoln(vector<int>& colors) {
        int n = colors.size();
        int maxD = 0;
        for(int i = 0 ; i < n ; i++) {
            // from left
            if(colors[i] != colors[0]) maxD = max(maxD, i);
            // from right
            if(colors[i] != colors[n-1]) maxD = max(maxD, (n-1)-i);
        }
        return maxD;
    }
};


int main()
{
    return 0;
}