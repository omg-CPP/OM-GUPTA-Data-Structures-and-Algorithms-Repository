// Leetcode : 3940 (EASY)

// You are given a sorted integer array nums and an integer k.

// Return an array such that each distinct element appears at most k times, while preserving the relative order of the elements in nums.

// Note: If a distinct element appears at least k times, then it must appear exactly k times in the resulting array.

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

// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            // new element
            if(i == 0 || (nums[i] != nums[i-1])) {
                count = 1;
            }
            else {
                count++;
            }
            // keep at most k copies
            if(count <= k) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}