// Leetcode : 78 (MEDIUM)

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

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
    // T.C. = O(n.2^n)
    // there are 2^n subsets and each of them holds ~n elements
    // S.C. = ~ O(n.2^n)
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        // no of subsets = 2^n
        int noOfSubsets = (1 << n);
        vector<vector<int>> ans;
        for(int num = 0 ; num <= noOfSubsets-1 ; num++) {
            vector<int> subset;
            for(int i = 0 ; i < n ; i++) {
                if(num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

int main()
{
    return 0;
}