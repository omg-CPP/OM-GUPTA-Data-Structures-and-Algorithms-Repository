// Leetcode : 3462 (MEDIUM)

// You are given a 2D integer matrix grid of size n x m, an integer array limits of length n, and an integer k. The task is to find the maximum sum of at most k elements from the matrix grid such that:

// The number of elements taken from the ith row of grid does not exceed limits[i].

// Return the maximum sum.

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

//                      sort
// T.C. = O(n*m) + O((n*m)*log(n*m)) + O(n*m)
// S.C. = O(n*m)
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<vector<int>> values;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                values.push_back({grid[i][j],i});
            }
        }
        sort(values.begin(), values.end(), greater<vector<int>>());
        long long ans = 0;
        for(int i = 0 ; i < n*m ; i++) {
            if(k > 0 && limits[values[i][1]] > 0) {
                ans += values[i][0];
                k--;
                limits[values[i][1]]--;
            }
            if(k == 0) break;
        }
        return ans;
    }
};


int main()
{
    return 0;
}