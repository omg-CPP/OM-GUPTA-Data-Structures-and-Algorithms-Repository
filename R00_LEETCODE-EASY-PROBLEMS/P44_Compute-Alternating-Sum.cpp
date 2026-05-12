// Leetcode : 3701 (EASY)

// You are given an integer array nums.

// The alternating sum of nums is the value obtained by adding elements at even indices and subtracting elements at odd indices. That is, nums[0] - nums[1] + nums[2] - nums[3]...

// Return an integer denoting the alternating sum of nums.

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
    int alternatingSum(vector<int>& nums) {
        int sum_even = 0, sum_odd = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(i % 2 == 0) sum_even += nums[i];
            else sum_odd += nums[i];
        }
        return sum_even - sum_odd;
    }
};

int main()
{
    return 0;
}