// Leetcode : 260 (MEDIUM)

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

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
    // Brute Force: M -> size of map
    // T.C. = O(N) + O(M), M = N/2 + 1
    // S.C. = O(M)
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int& num : nums) {
            mp[num]++;
        }
        vector<int> ans;
        for(auto& it : mp) {
            int freq = it.second;
            if(freq == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }

    // optimal way: concept of buckets
    // have to see striver lecture L6, L7 Bit Manipulation from 17 min
    // T.C. = O(N)
    // S.C. = O(1)
    
};



int main()
{
    return 0;
}

 