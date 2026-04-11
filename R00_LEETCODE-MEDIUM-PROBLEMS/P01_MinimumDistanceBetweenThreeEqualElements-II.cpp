// Leetcode : 3741 (MEDIUM)

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
    // when (i < j < k) -> ordered indices
    // |i-j| + |j-k| + |k-i| = 2 * (k-i)
    // minDist only depends on last and first index 
    // Optimal Approach : using hashmap with indices
    // storing all indices which corresponds to same value
    // T.C. = O(N) :: Each index in the array is processed only once across all vectors.
    // S.C. = O(N) :: hashmap 
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // storing indexes of each value
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        // Process each value
        for(auto& it : mp) {
            vector<int>& indices = it.second;
            // we need atleast 3 occurences
            if(indices.size() < 3) continue;

            // check for consecutive triplets
            for(int i = 0 ; i+2 < indices.size() ; i++) {
                minDist = min(minDist, 2*(indices[i+2] - indices[i]));
            }
        }
        return (minDist == INT_MAX) ? -1 : minDist;
    }
};

int main()
{
    return 0;
}