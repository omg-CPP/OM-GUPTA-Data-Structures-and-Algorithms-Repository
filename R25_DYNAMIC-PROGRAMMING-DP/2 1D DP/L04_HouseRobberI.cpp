// Leetcode : 198

#include <iostream>
#include <vector>
using namespace std;

// Question is solved like 0-based indexing [0->n-1]
// *********************** Memoization DP *************************
// T.C. = O(N)
//        dp[]  rec stack space
// S.C. = O(N) + O(N)
int rob_Memoization(int idx, vector<int>& nums, vector<int>& dp) {
    // base cases
    if(idx == 0) {
        return nums[idx];
    }
    if(idx < 0) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int pick = nums[idx] + rob_Memoization(idx-2,nums,dp);
    int notPick = 0 + rob_Memoization(idx-1,nums,dp);
    return dp[idx] = max(pick,notPick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,-1);
    return rob_Memoization(n-1,nums,dp);
}


// *********************** Tabulation DP *************************
// T.C. = O(N)
//        dp[] 
// S.C. = O(N) 
int rob_Tabulation(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    vector<int> dp(n,-1);
    // base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2 ; i <= n-1 ; i++) {
        int pick = nums[i] + dp[i-2];
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick,notPick);
    }
    return dp[n-1];
}


// *********************** Space Optimisation *************************
// T.C. = O(N)
// S.C. = 1
int rob_SpaceOptimised(vector<int>& nums) {
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1 ; i <= n-1 ; i++) {
        int pick = nums[i];
        if(i > 1) {
            pick += prev2;
        }
        int notPick = 0 + prev1;
        int curi = max(pick,notPick);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int main()
{
    return 0;
}