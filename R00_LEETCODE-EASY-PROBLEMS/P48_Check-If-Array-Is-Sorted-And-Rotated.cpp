// Leetcode : 1752 (EASY)

// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

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

// Brute Force Approach: Trying for every rotation possible
// T.C. = O(N^2)
// S.C. = O(N) :: sorted[]
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // we fill try to make the sorted array 
        vector<int> sorted(n,0);
        // this loops try to make sure that how many rotations are made 
        for(int r = 0 ; r < n ; r++) {
            int idx = 0;
            // sorted part starts from r
            for(int i = r ; i < n ; i++) {
                sorted[idx++] = nums[i];
            }
            for(int i = 0 ; i < r ; i++) {
                sorted[idx++] = nums[i];
            }
            // check if the array is sorted
            bool isSorted = true;
            for(int i = 0 ; i < n-1 ; i++) {
                if(sorted[i] > sorted[i+1]) {
                    isSorted = false;
                    break;
                }
            }
            if(isSorted) return true;
        }
        return false;
    }
};

// 0 -> no rotation 
// n-1 -> last rotation
// if array = 1 2 3 4 5 -> 0
// 5 1 2 3 4 -> 1
// 4 5 1 2 3 -> 2
// 3 4 5 1 2 -> 3
// 2 3 4 5 1 -> 4
// 1 2 3 4 5 -> 5 -> 0 rotations


// Optimal Approach:
// T.C. = O(N)
// S.C. = O(1)
class Solution_ {
public:
    // we need to check that peak should be atmost 1 in circular fashion
    bool check(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] > nums[(i+1) % n]) {
                peak++;
            }
        }
        return peak <= 1;
    }
};

int main()
{
    return 0;
}