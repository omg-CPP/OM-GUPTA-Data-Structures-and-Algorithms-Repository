// Leetcode : 137 (MEDIUM)

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

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
    // N -> size of array, M -> size of map = N/3 + 1
    // T.C. = O(N) + O(M)
    // S.C. = O(M) :: map
    int singleNumberI(vector<int>& nums) {
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


    // optimal approach using bitwise operator
    // T.C. = O(N*32)
    // S.C. = O(1)
    int singleNumberII(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bit = 0 ; bit <= 31 ; bit++) {
            int count = 0;
            for(int i = 0 ; i < n ; i++) {
                if(nums[i] & (1 << bit)) { // set bit
                    count++;
                }
            }
            // setbits = (3k + 1) type
            if(count % 3 == 1) { // single number is 1 at this bit
                ans = (ans | (1 << bit));
            }
            // count % 3 == 0
            // otherwise setbits would be 3k type,
            // which means single number at this bit
            // would be 0
        }
        return ans;
    }

    // optimal approach using sorting
    // T.C. = O(N*logN) + O(N/3) = O(N*logN)
    // S.C. = O(1)
    int singleNumberIII(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1 ; i < n ; i += 3) {
            if(nums[i] != nums[i-1]) {
                return nums[i-1];
            }
        }
        return nums[n-1];
    }

    // way 4: concept of buckets
    // have to see striver lecture L6 Bit Manipulation from 17 min
    // T.C. = O(N)
    // S.C. = O(1)
};

int main()
{
    return 0;
}