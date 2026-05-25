// Leetcode : 2540 (EASY)

// Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

// Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.


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

// Naive Approach : Set
// T.C. = O(M+N)
// S.C. = O(M) : set1{}
class Solution_1 {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        // Search for each element of nums2 in set1
        // Return the first common element found
        for(int& num : nums2) {
            if(set1.find(num) != set1.end()) {
                return num;
            }
        }
        return -1;
    }
};

// Better : Two Pointers Approach
// T.C. = O(M+N)
// S.C. = O(1)
class Solution_2 {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // we need to first intersecting element of both arrays
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;
        while(i < m && j < n) {
            if(nums1[i] == nums2[j]) {
                return nums1[i];
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};

// Optimal Approach : Binary Search
// T.C. = O(M*logN)
// S.C. = O(1)
class Solution_3 {
private:
    bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }

public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Binary search should be done on the larger array
        // If nums1 is longer, call getCommon with the arrays swapped
        if(nums1.size() > nums2.size()) {
            return getCommon(nums2,nums1);
        }
        for(int& num : nums1) {
            if(binarySearch(nums2,num) == true) {
                return num;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}