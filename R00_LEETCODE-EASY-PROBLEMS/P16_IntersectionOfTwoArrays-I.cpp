// Leetcode : 349 (EASY)

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

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

// T.C. = O(N*logN) + O(M*logM) + O(M+N)
// S.C. = O(uniqueCommonElements) :: set
class Solution_ {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_set<int> st;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                st.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else { // nums1[i] > nums2[j]
                j++;
            }
        }
        vector<int> intersection(st.begin(),st.end());
        return intersection;
    }
};

// Optimal Approach
class Solution {
public:
    // as order does not matter, we use unordered_set
    // N -> nums1.size(), M -> nums2.size()
    // T.C. = O(N+M) :: nums1 set insert + nums2 traverse
    // S.C. = O(N) :: set
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int num : nums2) {
            if(s1.count(num)) {
                result.insert(num); // O(1)
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};


int main()
{
    return 0;
}