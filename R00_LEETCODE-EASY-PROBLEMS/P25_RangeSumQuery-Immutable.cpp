// Leetcode : 303 (EASY)

// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


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

class NumArray {
public:
    vector<int> prefix;
    // Construction of prefixSum array :: O(N)
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n,0);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    // O(1)
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix[right];
        }
        else {
            return prefix[right] - prefix[left-1];
        }
    }
};


int main()
{
    return 0;
}