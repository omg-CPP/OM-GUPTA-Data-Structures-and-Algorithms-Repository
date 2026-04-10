// Leetcode : 3740 (EASY)

// You are given an integer array nums.
// A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
// The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
// Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

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
    // brute force would be to check all triplets
    // T.C. = O(N^3)
    // S.C. = O(1)
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minDist = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                // skip early if values don't match
                if(nums[i] != nums[j]) continue;
                for(int k = j+1 ; k < n ; k++) {
                    if(nums[i] == nums[k]) {
                        int dist = abs(i-j) + abs(j-k) + abs(k-i);
                        minDist = min(minDist,dist);
                    }
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};

int main()
{
    return 0;
}