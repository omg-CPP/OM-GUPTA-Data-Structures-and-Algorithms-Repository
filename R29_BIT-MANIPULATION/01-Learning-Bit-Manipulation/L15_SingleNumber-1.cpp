// Leetcode : 136 (EASY)

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Each element in the array appears twice except for one element which appears only once.

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
    // Brute Force
    // N -> size of array
    // T.C. = O(N) + O(M), M = size of map = N/2 + 1
    // S.C. = O(M) :: map
    int singleNumber_NaiveSolution(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int& num : nums) {
            mp[num]++;
        }

        for(auto& it : mp) {
            int freq = it.second;
            if(freq == 1) {
                return it.first;
            }
        }
        return 0;
    }

    // property:
    // 1. a ^ a = 0
    // 2. a ^ 0 = a
    // Optimal Approach
    // T.C. = O(N)
    // S.C. = O(1)
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(int i = 0 ; i < n ; i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};


int main()
{
    return 0;
}