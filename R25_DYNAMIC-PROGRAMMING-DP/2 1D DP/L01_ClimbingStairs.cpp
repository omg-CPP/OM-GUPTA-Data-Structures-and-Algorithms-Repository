// Leetcode : 70

#include <iostream>
#include <vector>
using namespace std;

// Memoization
// T.C. = O(N)
//        dp[]  rec stack space
// S.C. = O(N) + O(N)
int climbStairs_Memoization_DP(int n, vector<int>& dp) {
    // if no steps are there
    if(n == 1) {
        return 1;
    }
    // if one step is there
    if(n == 2) {
        return 2;
    }
    // if we have computed before
    if(dp[n] != -1) {
        return dp[n];
    }
    int ways1 = climbStairs_Memoization_DP(n-1,dp);
    int ways2 = climbStairs_Memoization_DP(n-2,dp);
    return dp[n] = ways1 + ways2;
}

int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return climbStairs_Memoization_DP(n,dp);
}


// Tabulation
// T.C. = O(N)
//        dp[]
// S.C. = O(N)
int climbStairs_Tabulation_DP(int n, vector<int>& dp) {
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3 ; i <= n ; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int climbStairs(int n) {
    if(n <= 2) {
        return n;
    }
    vector<int> dp(n+1,-1);
    return climbStairs_Tabulation_DP(n,dp);
}

int main()
{
    return 0;
}