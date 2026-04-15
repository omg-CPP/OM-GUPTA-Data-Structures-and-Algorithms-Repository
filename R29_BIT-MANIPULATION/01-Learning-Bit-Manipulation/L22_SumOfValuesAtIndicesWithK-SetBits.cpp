// Leetcode : 2859 (EASY)

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
    // calculate set bit
    int countSetBits(int n) {
        int count = 0;
        while(n != 0) {
            n = n & (n-1);
            count++;
        }
        return count;
    }

    // T.C. = O(n*logn)
    // S.C. = O(1)
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            if(countSetBits(i) == k) {
                sum += nums[i];
            }
        }
        return sum;
    }


    // optimal way: using DP
    // T.C. = O(n)
    //        dp[]
    // S.C. = O(n)
    int sumIndicesWithKSetBits_Optimal(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k == 0) return nums[0];
        if(n == 1 && k != 0) return 0;
        int sum = 0;
        vector<int> dp(n,0);
        dp[0] = 0;
        if(k == 0) {
            sum += nums[0];
            return sum;
        }
        for(int i = 1 ; i < n ; i++) {
            if(i & 1) dp[i] = dp[i/2] + 1; // odd
            else dp[i] = dp[i/2]; // even
            if(dp[i] == k) sum += nums[i];
        }
        return sum;
    }
};

int main()
{
    return 0;
}