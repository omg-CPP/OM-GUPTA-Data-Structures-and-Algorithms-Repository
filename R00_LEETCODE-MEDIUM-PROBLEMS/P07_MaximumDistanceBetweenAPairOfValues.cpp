// Leetcode : 1855 (MEDIUM)

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

// Approach: Two Pointers
// T.C. = O(M+N)
// S.C. = O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxD = 0;
        int i = 0; // nums1[]
        int j = 0; // nums2[]
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                maxD = max(maxD,j-i);
                j++;
            }
            else { // nums1[i] > nums2[j]
                i++;
            }
        }
        return maxD;
    }
};

int main()
{
    return 0;
}