// Find no of ways to construct sum = n by throwing a dice one
// or more times. Each throw produces a outcome of 1 to 6.

#include <iostream>
#include <vector>
using namespace std;

// Memoization DP
// T.C. = O(N)
//        dp[]  rec stack space
// S.C. = O(N) + O(N)
int fun_Mem(int n, vector<int>& dp) {
    // base cases
    if(n < 0) return 0;
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    // checking if we have pre-computed
    if(dp[n] != -1) {
        return dp[n];
    }
    // writing recurrences
    int ans = fun_Mem(n-1,dp)+fun_Mem(n-2,dp)+fun_Mem(n-3,dp)+fun_Mem(n-4,dp)+fun_Mem(n-5,dp)+fun_Mem(n-6,dp);
    return dp[n] = ans;
}

int diceCombinations_Mem(int n) {
    vector<int> dp(n+1,-1);
    return fun_Mem(n,dp);
}

// Tabulation DP
// T.C. = O(N)
//        dp[]
// S.C. = O(N)
int diceCombinations_Tab(int n) {
    vector<int> dp(n+1,0);
    // base cases
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= n ; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        if(i >= 4) {
            dp[i] += dp[i-4];
        }
        if(i >= 5) {
            dp[i] += dp[i-5];
        }
        if(i >= 6) {
            dp[i] += dp[i-6];
        }
    }
    return dp[n];
}

int diceCombinations(int n) {
    vector<int> dp(n+1,0);
    // base case
    // there is one way to attain sum = 0, not throw the dice
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        // dice combinations
        for(int j = 1 ; j <= 6 ; j++) {
            if(j <= i) {
                // transition
                dp[i] += dp[i-j];
            }
        }
    }
    // final subproblem
    return dp[n];
}

int main()
{
    cout<<diceCombinations_Mem(0)<<endl; // 1
    cout<<diceCombinations_Mem(1)<<endl; // 1
    cout<<diceCombinations_Mem(2)<<endl; // 2
    cout<<diceCombinations_Mem(3)<<endl; // 4
    cout<<diceCombinations_Mem(4)<<endl; // 8
    cout<<diceCombinations_Mem(5)<<endl; // 16
    cout<<diceCombinations_Mem(6)<<endl; // 32
    cout<<diceCombinations_Mem(7)<<endl; // 63

    cout<<endl<<"***************************************"<<endl<<endl;

    cout<<diceCombinations_Tab(0)<<endl; // 1
    cout<<diceCombinations_Tab(1)<<endl; // 1
    cout<<diceCombinations_Tab(2)<<endl; // 2
    cout<<diceCombinations_Tab(3)<<endl; // 4
    cout<<diceCombinations_Tab(4)<<endl; // 8
    cout<<diceCombinations_Tab(5)<<endl; // 16
    cout<<diceCombinations_Tab(6)<<endl; // 32
    cout<<diceCombinations_Tab(7)<<endl; // 63

    cout<<endl<<"***************************************"<<endl<<endl;

    cout<<diceCombinations(0)<<endl; // 1
    cout<<diceCombinations(1)<<endl; // 1
    cout<<diceCombinations(2)<<endl; // 2
    cout<<diceCombinations(3)<<endl; // 4
    cout<<diceCombinations(4)<<endl; // 8
    cout<<diceCombinations(5)<<endl; // 16
    cout<<diceCombinations(6)<<endl; // 32
    cout<<diceCombinations(7)<<endl; // 63
    return 0;
}

