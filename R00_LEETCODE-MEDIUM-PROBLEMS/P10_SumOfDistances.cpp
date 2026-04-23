// Leetcode : 2615 (MEDIUM)

// You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
// Return the array arr.

// Example 1:

// Input: nums = [1,3,1,1,2]
// Output: [5,0,3,4,0]
// Explanation: 
// When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
// When i = 1, arr[1] = 0 because there is no other index with value 3.
// When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
// When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
// When i = 4, arr[4] = 0 because there is no other index with value 2. 

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
typedef long long ll;

// Process:
//           0  1  2  3  4  5  6  7
// nums[] = {1, 2, 1, 1, 1, 1, 2, 1}
// for arr[3],
//          left of i         right of i
//     |3 - 0| + |3 - 2| + |3 - 4| + |3 - 5| + |3 - 7|
//     (i - 0) + (i - 2) + (4 - i) + (5 - i) + (7 - i)
//          2*i - (0+2)  + (4+5+7) - 3*i
// 

// T.C. = O(N) + O(N) = O(N)
// S.C. = O(N) + O(N) = O(N)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> arr(n,0);
        unordered_map<int, ll> indexCount; // num[i] - > frequency
        unordered_map<int, ll> indexSum;   // nums[i] -> sum of all idx's
        

        // left to right
        for(int i = 0 ; i < n ; i++) {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];
            arr[i] += (freq*i - sum);

            indexCount[nums[i]]++;
            indexSum[nums[i]] += i;
        }

        indexCount.clear();
        indexSum.clear();

        // right to left
        for(int i = n-1 ; i >= 0 ; i--) {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];
            arr[i] += (sum - freq*i);

            indexCount[nums[i]]++;
            indexSum[nums[i]] += i;
        }
        return arr;
    }
};


int main()
{
    Solution* obj = new Solution();
    vector<int> nums = {1,3,1,1,2};
    vector<ll> arr = obj->distance(nums);
    for(ll& val : arr) cout<<val<<" ";
    // 5 0 3 4 0 
    cout<<endl;
    return 0;
}