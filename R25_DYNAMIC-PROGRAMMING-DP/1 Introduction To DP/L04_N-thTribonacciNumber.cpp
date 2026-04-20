// Leetcode 1137

// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

#include <iostream>
#include <vector>
using namespace std;

// Memoization DP
// T.C. = O(N)
//        dp[]   rec stack space
// S.C. = O(N) + O(N)
int tribonacci_Mem(int n, vector<int>& dp) {
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return 1;
    }
    // if pre-computed before
    if(dp[n] != -1) {
        return dp[n];
    }
    int one = tribonacci_Mem(n-1,dp);
    int two = tribonacci_Mem(n-2,dp);
    int three = tribonacci_Mem(n-3,dp);
    int ans = one + two + three;
    return dp[n] = ans;
}

int tribonacci(int n) {
    vector<int> dp(n+1,-1);
    return tribonacci_Mem(n,dp);
}


// Tabulation DP
// T.C. = O(N)
//        dp[]
// S.C. = O(N)
int tribonacci_Tab(int n) {
    // base cases
    if(n == 0 || n == 1) {
        return n;
    }
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3 ; i <= n ; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}


// Space Optimisation
// T.C. = O(N)
// S.C. = O(1)
int tribonacci_SpaceOptimised(int n) {
    if(n == 0) {
        return 0;
    }
    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 1;
    for(int i = 3 ; i <= n ; i++) {
        int curi = prev3 + prev2 + prev1;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int main()
{
    return 0;
}