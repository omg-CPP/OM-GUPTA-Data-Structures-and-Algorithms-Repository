// Leetcode : 509

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(N)
//        dp[]
// S.C. = O(N)
int fib_Tabulation_DP(int n, vector<int>& dp) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i <= n ; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib(int n) {
    if(n <= 1) {
        return n;
    }
    vector<int> dp(n+1,-1);
    return fib_Tabulation_DP(n,dp);
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}