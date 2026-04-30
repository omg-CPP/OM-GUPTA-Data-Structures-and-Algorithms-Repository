// Leetcode : 2435 (3D DP)

// So mathematically:
// (a + b) % M
// ((a % M) + b) % M
// ((a % M) + (b % M)) % M
// are equivalent.

#include <iostream>
#include <vector>
using namespace std;

// Memoization DP 
// T.C. = O(M*N*K)
//        dp[][][]  rec stack space
// S.C. = O(M*N*K) + O(M)
int MOD = 1e9 + 7;
// first writing the recursive solution
int fun_Mem(int r, int c, int currSum, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp) {
    int m = grid.size(); // rows
    int n = grid[0].size(); // columns
    // out of bound cases
    if(r < 0 || c < 0) {
        return 0;
    }
    // base case
    if(r == 0 && c == 0) {
        return ((currSum + grid[r][c]) % k == 0) ? 1 : 0;
    }
    // checking for pre-computation
    if(dp[r][c][currSum] != -1) {
        return dp[r][c][currSum];
    }
    // writing the recurrences
    int up = fun_Mem(r-1,c,(currSum+grid[r][c]) % k,grid,k,dp);
    int left = fun_Mem(r,c-1,(currSum+grid[r][c]) % k,grid,k,dp);
    return dp[r][c][currSum] = (up + left) % MOD;
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size(); // rows
    int n = grid[0].size(); // columns
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k,-1)));
    return fun_Mem(m-1,n-1,0,grid,k,dp);
}

int main()
{
    return 0;
}