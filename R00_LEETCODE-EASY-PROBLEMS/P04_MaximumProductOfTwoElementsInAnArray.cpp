// Leetcode : 1464 (EASY)

// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

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
    // T.C. = O(N)
    // S.C. = O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sec_maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            // track largest and second largest
            if(maxi < nums[i]) {
                sec_maxi = maxi;
                maxi = nums[i];
            }
            else if(sec_maxi < nums[i]) {
                sec_maxi = nums[i];
            }
        }
        return (maxi-1) * (sec_maxi-1);
    }
};


int main()
{
    return 0;
}