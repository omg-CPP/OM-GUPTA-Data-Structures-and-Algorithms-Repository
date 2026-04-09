// Leetcode : 3653 (MEDIUM)
// 1 <= n == nums.length <= 10^3
// 1 <= q == queries.length <= 10^3

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
    // worst case occurs when li = 0; ri = n-1 and ki = 1
    // Q -> queries.size() and N -> nums.size()
    // T.C. = O(Q.N) + O(N) = O(Q.N)
    // S.C. = O(1)
    int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            int ki = query[2];
            int vi = query[3];
            for(int idx = li ; idx <= ri ; idx += ki) {
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }
        int xorr = 0;
        for(int& num : nums) {
            xorr ^= num;
        }
        return xorr;
    }
};

int main()
{
    return 0;
}