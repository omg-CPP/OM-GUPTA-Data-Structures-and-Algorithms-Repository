// Follow Up Question

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// T.C. = O(N*K)
// S.C. = O(N) + O(N)
// Function to fidx the minimum cost to reach idxex 'idx' using at most 'k' jumps
int frogJump_Memoization(int idx, vector<int>& height, vector<int>& dp, int k) {
    // Base case: starting point has zero cost
    if(idx == 0) {
        return 0;
    }
    // Return already computed result
    if(dp[idx] != -1) {
        return dp[idx];
    }
    // Initialize minimum steps as large value
    int minSteps = INT_MAX;

    // Try all possible jumps from 1 to k
    for(int j = 1 ; j <= k ; j++) {
        // Ensure jump does not go out of bounds
        if(idx - j >= 0) {
            // Cost of taking the jump
            int jump = frogJump_Memoization(idx-j, height, dp, k) + abs(height[idx] - height[idx-j]);
            // Store the minimum cost
            minSteps = min(jump, minSteps);
        }
    }
    // Save the result in dp array
    return dp[idx] = minSteps;
}

// Function to get minimum cost to reach end
int solveI(int n, vector<int>& height, int k) {
    // DP array initialized to -1
    vector<int> dp(n,-1);
    // Start recursion from last idxex
    return frogJump_Memoization(n-1, height, dp, k);
}

// ********************************* Tabulation DP **************************************************
// T.C. = O(N*K)
// S.C. = O(N) 
// Function to compute the minimum cost to reach the end using at most 'k' jumps
int frogJump_Tabulation(int n, vector<int>& height, vector<int>& dp, int k) {
    // Base case: cost to reach the first stone is 0
    dp[0] = 0;

    // Iterate over each stone
    for(int i = 1 ; i <= n-1 ; i++) {
        // Initialize the minimum cost for this stone as large value
        int minSteps = INT_MAX;

        // Try all possible jump lengths from 1 to k
        for(int j = 1 ; j <= k ; j++) {
            // Ensure jump doesn't go out of bounds
            if(i-j >= 0) {
                // Cost of jumping from (i - j) to i
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                // Keep track of the minimum cost
                minSteps = min(minSteps, jump);
            }
        }

        // Store the computed minimum cost for this stone
        dp[i] = minSteps;
    }

    // The last element of dp stores the answer
    return dp[n-1];
}

// Main function to solve the problem
int solveII(int n, vector<int>& height, int k) {
    // Initialize DP array with -1
    vector<int> dp(n, -1);
    // Fill DP array iteratively
    return frogJump_Tabulation(n, height, dp, k);
}

int main()
{
    // Heights of stones
    vector<int> height= {30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    // Output the minimum cost
    cout<<solveI(n, height, k)<<endl; // 40
    cout<<solveII(n, height, k)<<endl; // 40
    return 0;
}