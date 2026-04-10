// Leetcode : 977 (EASY)

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

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

// Two Pointers Approach
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int i = 0;
        int j = n-1;
        int k = n-1;
        // equality case comes as single element need to be filled also
        while(i <= j) {
            if(abs(nums[i]) >= abs(nums[j])) {
                ans[k--] = (nums[i]*nums[i]);
                i++;
            }
            else { // abs(nums[i]) < abs(nums[j])
                ans[k--] = (nums[j]*nums[j]);
                j--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}