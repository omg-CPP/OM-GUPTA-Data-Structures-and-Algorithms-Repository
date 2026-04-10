// Leetcode : 88 (EASY)

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

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

// T.C. = O(M+N)
// S.C. = O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else { // nums1[i] < nums2[j]
                nums1[k--] = nums2[j--];
            }
        }
        // Need not to overide nums1 elements till i >= 0 when j < 0,
        // as they are already sorted, we only need to move elements
        // manually when i < 0, and nums2 elements are still to be filled in nums1...
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    return 0;
}