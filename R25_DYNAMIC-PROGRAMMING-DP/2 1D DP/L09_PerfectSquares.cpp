// Leetcode : 279

// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int fun_Mem(int n, vector<int>& dp) {
    // base case
    if(n == 0) {
        return 0;
    }

    // check if dp[] is pre-computed
    if(dp[n] != -1) {
        return dp[n];
    }

    // writing recurrence
    int minCount = INT_MAX;
    for(int i = 1 ; i*i <= n ; i++) {
        int count = 1 + fun_Mem(n-i*i,dp);
        minCount = min(minCount,count);
    }
    return dp[n] = minCount;
}

int numSquares(int n) {
    vector<int> dp(n+1,-1);
    return fun_Mem(n,dp);
}


// Tabulation DP
int numSquares(int n) {
    vector<int> dp(n+1,INT_MAX);
    // base case
    dp[0] = 0;

    // filling the dp[] table
    for(int i = 1 ; i <= n ; i++) {
        // check how many perfect squares numbers it can take
        int minCount = INT_MAX;
        for(int j = 1 ; j*j <= i ; j++) {
            dp[i] = min(dp[i], 1 + dp[i-j*j]);
        }
    }
    return dp[n];
}

int main()
{
    int n = 12;
    cout<<numSquares(n)<<endl; // 3
    return 0;
}