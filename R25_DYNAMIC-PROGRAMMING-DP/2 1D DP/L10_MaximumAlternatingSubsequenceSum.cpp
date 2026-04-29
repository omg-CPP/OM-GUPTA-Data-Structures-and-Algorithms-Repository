// Leetcode : 1911

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// Memoization DP
// T.C. = O(NX2)
//        dp[][]   rec stack space
// S.C. = O(NX2) + O(N)
ll fun_Mem(int idx, bool flag, vector<int>& nums, vector<vector<ll>>& dp) {
    int n = nums.size();
    // base cases
    if(idx == n) {
        return 0;
    }

    // check if dp[][] is pre-computed
    if(dp[idx][flag] != -1) {
        return dp[idx][flag];
    }

    // writing the recurrences
    ll skip = 0 + fun_Mem(idx+1,flag,nums,dp);
    ll val = nums[idx];
    if(flag == false) { // odd index element
        val = -val;
    }
    ll take = val + fun_Mem(idx+1,!flag,nums,dp);
    return dp[idx][flag] = max(skip,take);
}

long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<ll>> dp(n, vector<ll>(2,-1));
    return fun_Mem(0,true,nums,dp);
}


typedef long long ll;
// Tabulation DP
// T.C. = O(NX2)
//        dp[][]  
// S.C. = O(NX2) 
long long maxAlternatingSum_Tab(vector<int>& nums) {
    int n = nums.size();
    vector<vector<ll>> dp(n+1, vector<ll>(2,0));
    // base cases
    dp[n][true] = 0;
    dp[n][false] = 0;

    // filling of dp[][] table
    for(int idx = n-1 ; idx >= 0 ; idx--) {
        // even
        dp[idx][true] = max(0 + dp[idx+1][true], nums[idx] + dp[idx+1][false]);
        // odd
        dp[idx][false] = max(0 + dp[idx+1][false], -nums[idx] + dp[idx+1][true]);
    }
    return dp[0][true];
}


int main()
{
    vector<int> nums = {14,20,1,2};
    cout<<maxAlternatingSum(nums)<<endl;
    cout<<maxAlternatingSum_Tab(nums)<<endl;
    return 0;
}