// Leetcode : 746

#include <iostream>
#include <vector>
using namespace std;

// end to start Process
int fun(int idx, vector<int>& cost, vector<int>& dp) {
    // if jump starts from index 0
    if(idx == 0) {
        return cost[0];
    }
    // if jump starts from index 1
    if(idx == 1) {
        return cost[1];
    }
    // checking if the ans is pre-computed
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int ans = cost[idx] + min(fun(idx-1,cost,dp), fun(idx-2,cost,dp));
    return dp[idx] = ans;
}

int minCostClimbingStairsI(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n,-1);
    int ans = min(fun(n-1,cost,dp), fun(n-2,cost,dp));
    return ans;
}

// idea is all about if cost of reaching index n-1 is smaller than in that case
// only one jump is needed to reach at the top 
// but if cost of reaching index n-2 is smaller than in that case two jumps 
// will be required to reach at the top

// start to end process
// T.C. = O(2^N)
// S.C. = O(N)
int fun_Recursive(int idx, vector<int>& cost) {
    int n = cost.size();
    if(idx >= n) {
        return 0;
    }
    int left = cost[idx] + fun_Recursive(idx+1,cost);
    int right = cost[idx] + fun_Recursive(idx+2,cost);
    return min(left,right);
}

int minCostClimbingStairsII(vector<int>& cost) {
    int n = cost.size();
    return min(fun_Recursive(0,cost),fun_Recursive(1,cost));
}

// ****************************** Memoization DP ***********************
// T.C. = O(N)
//        dp[]   rec stack space
// S.C. = O(N) + O(N)
int fun_Memoization(int idx, vector<int>& cost, vector<int>& dp) {
    int n = cost.size();
    if(idx >= n) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int left = cost[idx] + fun_Memoization(idx+1,cost,dp);
    int right = cost[idx] + fun_Memoization(idx+2,cost,dp);
    return dp[idx] = min(left,right);
}

int minCostClimbingStairsIII(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1,-1);
    return min(fun_Memoization(0,cost,dp),fun_Memoization(1,cost,dp));
}

// **************************** Tabulation DP **************************
// T.C. = O(N)
// S.C. = O(N)
int minCostClimbingStairs_Tabulation(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1,-1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2 ; i < n ; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

// ***************************** Space Optimised *****************************
// T.C. = O(N) 
// S.C. = O(1)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev2 = cost[0];
    int prev1 = cost[1];
    for(int i = 2 ; i < n ; i++) {
        int curi = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curi;
    }
    return min(prev2, prev1);
}

int main()
{
    vector<int> cost = {10,15,20};
    cout<<minCostClimbingStairsI(cost)<<endl; // 15
    cout<<minCostClimbingStairsII(cost)<<endl; // 15
    cout<<minCostClimbingStairsIII(cost)<<endl; // 15
    cout<<minCostClimbingStairs(cost)<<endl; // 15
    return 0;
}

// {10,15,20}
// if it begin from index n-1 i.e. 2 than ans will be 20 + min(15,10) = 30 => one jump to top
// but if begins from index n-2 i.e. 1 than ans will be 15 => 2 jumps to top