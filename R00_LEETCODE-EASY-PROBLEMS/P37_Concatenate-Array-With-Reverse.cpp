// Leetcode : 3925 (EASY)

// You are given an integer array nums of length n.

// Construct a new array ans of length 2 * n such that the first n elements are the same as nums, and the next n elements are the elements of nums in reverse order.

// Formally, for 0 <= i <= n - 1:

// ans[i] = nums[i]
// ans[i + n] = nums[n - i - 1]
// Return an integer array ans.

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
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n,0);
        for(int i = 0 ; i < n ; i++) {
            ans[i] = nums[i];
            ans[i+n] = nums[n-i-1];
        }
        return ans;
    }
};

int main()
{
    return 0;
}