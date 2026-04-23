// Leetcode : 2121 (MEDIUM) same as Leetcode : 2615 (MEDIUM)

// Example 1:

// Input: arr = [2,1,3,1,2,3,3]
// Output: [4,2,7,2,4,4,5]
// Explanation:
// - Index 0: Another 2 is found at index 4. |0 - 4| = 4
// - Index 1: Another 1 is found at index 3. |1 - 3| = 2
// - Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
// - Index 3: Another 1 is found at index 1. |3 - 1| = 2
// - Index 4: Another 2 is found at index 0. |4 - 0| = 4
// - Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
// - Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5

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
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll> nums(n,0);
        unordered_map<int, ll> indexCount; // num[i] - > frequency
        unordered_map<int, ll> indexSum;   // nums[i] -> sum of all idx's
        

        // left to right
        for(int i = 0 ; i < n ; i++) {
            ll freq = indexCount[arr[i]];
            ll sum = indexSum[arr[i]];
            nums[i] += (freq*i - sum);

            indexCount[arr[i]]++;
            indexSum[arr[i]] += i;
        }

        indexCount.clear();
        indexSum.clear();

        // right to left
        for(int i = n-1 ; i >= 0 ; i--) {
            ll freq = indexCount[arr[i]];
            ll sum = indexSum[arr[i]];
            nums[i] += (sum - freq*i);

            indexCount[arr[i]]++;
            indexSum[arr[i]] += i;
        }
        return nums;
    }
};

int main()
{
    return 0;
}