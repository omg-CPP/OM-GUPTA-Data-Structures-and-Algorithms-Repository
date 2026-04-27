// Frog Jump : GFG

// Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ******************** Recursive Solution ********************
// T.C. = O(2^N)
// S.C. = O(N)
int minCost_Recursive(int n, vector<int>& height) {
    if(n == 0) {
        return 0;
    }
    int left = minCost_Recursive(n-1, height) + abs(height[n] - height[n-1]);
    int right = INT_MAX;
    if(n > 1) {
        right = minCost_Recursive(n-2, height) + abs(height[n] - height[n-2]);
    }
    return min(left, right);
}

// int minCost(vector<int>& height) {
//     // Code here
//     int n = height.size();
//     // passing the last index as solving the problem as 0-based indexing
//     return minCost_Recursive(n-1,height);
// }

// ************************************************************************

// ******************** Recursive Memoization Solution ********************
// T.C. = O(N)
//        dp[]  rec stack space
// S.C. = O(N) + O(N)
int minCost_Memoization_DP(int n, vector<int>& height, vector<int>& dp) {
    // base case
    if(n == 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int left = minCost_Memoization_DP(n-1, height, dp) + abs(height[n] - height[n-1]);
    int right = INT_MAX;
    if(n > 1) {
        right = minCost_Memoization_DP(n-2, height, dp) + abs(height[n] - height[n-2]);
    }
    return dp[n] = min(left, right);
}

int minCost(vector<int>& height) {
    // Code here
    int n = height.size();
    // as solving like 0-based indexing so dp array of size n will work (0->n-1)
    vector<int> dp(n,-1);
    // passing the last index as solving the problem as 0-based indexing
    return minCost_Memoization_DP(n-1,height,dp);
}

// ************************************************************************

// ******************** Tabulation Solution ********************
// Bottom Up Solution
// T.C. = O(N)
//        dp[]  
// S.C. = O(N)
int minCost_Tabulation_DP(vector<int>& height) {
    int n = height.size();
    // as solving like 0-based indexing so dp array of size n will work (0->n-1)
    vector<int> dp(n,-1);
    // passing the last index as solving the problem as 0-based indexing
    dp[0] = 0;
    for(int i = 1 ; i <= n-1 ; i++) {
        int left = dp[i-1] + abs(height[i] - height[i-1]);
        int right = INT_MAX;
        if(i > 1) {
            right = dp[i-2] + abs(height[i] - height[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

// **************************** space optimisation **********************************
// T.C. = O(N)
// S.C. = O(1)
int minCost_SpaceOptimised(vector<int>& height) {
    int n = height.size();
    int prev2 = 0;
    int prev1 = 0;
    for(int i = 1 ; i <= n-1 ; i++) {
        int left = prev1 + abs(height[i] - height[i-1]);
        int right = INT_MAX;
        if(i > 1) {
            right = prev2 + abs(height[i] - height[i-2]);
        }
        int curi = min(left,right);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int main()
{
    vector<int> height = {30,10,60,10,60,50};
    cout<<minCost(height)<<endl; // 40
    cout<<minCost_Tabulation_DP(height)<<endl; // 40
    cout<<minCost_SpaceOptimised(height)<<endl; // 40
    return 0;
}