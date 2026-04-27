// Leetcode : 3912 (EASY)

// You are given an integer array nums.
// An element nums[i] is considered valid if it satisfies at least one of the following conditions:
// It is strictly greater than every element to its left.
// It is strictly greater than every element to its right.
// The first and last elements are always valid.
// Return an array of all valid elements in the same order as they appear in nums.

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
    // T.C. = O(N)
    // S.C. = O(N)
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // pre-compute the max to left and right of every index 
        vector<int> maxiLeft(n,0);
        vector<int> maxiRight(n,0);

        // build maxiLeft
        maxiLeft[0] = INT_MIN; // nothing to the left
        for(int i = 1 ; i < n ; i++) {
            maxiLeft[i] = max(maxiLeft[i-1], nums[i-1]);
        }

        // build maxiRight
        maxiRight[n-1] = INT_MIN; // nothing to the right
        for(int i = n-2 ; i >= 0 ; i--) {
            maxiRight[i] = max(maxiRight[i+1], nums[i+1]);
        }

        // check for validity
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] > maxiLeft[i] || nums[i] > maxiRight[i]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}