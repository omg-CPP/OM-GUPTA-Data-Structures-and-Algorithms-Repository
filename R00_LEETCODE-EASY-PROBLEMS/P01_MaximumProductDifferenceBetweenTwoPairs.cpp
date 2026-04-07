// Leetcode : 1913 (EASY)

// The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

// For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
// Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

// Return the maximum such product difference.

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
    // brute force: sorting
    // T.C. = O(N*logN)
    // S.C. = O(1)
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return (nums[n-2]*nums[n-1] - nums[0]*nums[1]);
    }

    // optimal: finding max, sec_max, min and sec_min
    // T.C. = O(N)
    // S.C. = O(1)
    int maxProductDifference_(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sec_maxi = INT_MIN;
        int mini = INT_MAX;
        int sec_mini = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            // track largest and second largest
            if(maxi < nums[i]) {
                sec_maxi = maxi;
                maxi = nums[i];
            }
            else if(sec_maxi < nums[i]) {
                sec_maxi = nums[i];
            }
            // track smallest and second smallest
            if(mini > nums[i]) {
                sec_mini = mini;
                mini = nums[i];
            }
            else if(sec_mini > nums[i]) {
                sec_mini = nums[i];
            }
        }
        return (maxi*sec_maxi - mini*sec_mini);
    }
};


int main()
{
    return 0;
}