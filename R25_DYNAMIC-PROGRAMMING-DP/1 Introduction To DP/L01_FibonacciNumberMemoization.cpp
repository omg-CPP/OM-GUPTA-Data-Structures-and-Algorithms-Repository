// Leetcode : 509

#include <iostream>
#include <vector>
using namespace std;

// exponential Time Complexity
int fib_Recursive(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    int fibo = fib_Recursive(n-1) + fib_Recursive(n-2);
    return fibo;
}

// Memoization Approach :: Top Down Approach
// T.C. = O(N) "Linear Pattern" -> See Tree Diagram
//       dp[]   rec stack space
// S.C. = O(N) + O(N)
int fib_Memoization_DP(int n, vector<int>& dp) {
    if(n <= 1) {
        return n;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fib_Memoization_DP(n-1,dp) + fib_Memoization_DP(n-2,dp);
    return dp[n];
}

int fib(int n) {
    vector<int> dp(n+1,-1);
    return fib_Memoization_DP(n,dp);
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}