// Leetcode : 3904 (MEDIUM)

// You are given an integer array nums of length n and an integer k.
// For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

// In other words:
// max(nums[0..i]) is the largest value among the elements from index 0 to index i.
// min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
// An index i is called stable if its instability score is less than or equal to k.
// Return the smallest stable index. If no such index exists, return -1.

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
    // T.C. = O(N) + O(N) = O(N)
    // S.C. = O(N)
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // pre-compute minimum from any i to n-1 idx
        vector<int> mini(n,0);
        mini[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            mini[i] = min(mini[i+1],nums[i]);
        }
        // now traverse the loop
        int maxi = INT_MIN;
        int idx = -1;
        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi,nums[i]);
            if(maxi - mini[i] <= k) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};

int main()
{
    return 0;
}