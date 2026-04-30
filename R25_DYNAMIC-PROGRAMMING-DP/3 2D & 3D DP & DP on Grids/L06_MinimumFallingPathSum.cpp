// Leetcode : 931

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Memoization DP Approach
// T.C. = O(M*N)
//        dp[][]   rows (path)
// S.C. = O(M*N) + O(M)
int solve(vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp) {
    int m = mat.size();
    int n = mat[0].size();
    // base cases
    if(r < 0 || c < 0 || c > n-1) {
        return 1e9;
    }
    if(r == 0) {
        return mat[r][c];
    }
    // checking for pre-computation
    if(dp[r][c] != -1) {
        return dp[r][c];
    }
    // move diagonally to the left
    int left = mat[r][c] + solve(mat,r-1,c-1,dp);
    // move directly down
    int up = mat[r][c] + solve(mat,r-1,c,dp);
    // move diagonally to the right
    int right = mat[r][c] + solve(mat,r-1,c+1,dp);
    return dp[r][c] = min(left,min(up,right));
}

// Writing first the recursive code
int minFallingPathSum(vector<vector<int>>& mat) {
    // code here
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    // as we can start from any column of the first row
    int mini = INT_MAX;
    for(int j = 0 ; j < n ; j++) {
        mini = min(mini, solve(mat,m-1,j,dp));
    }
    return mini;
}

// Writing the Tabulation DP code 
// T.C. = O(N) + O(M*N) + O(N) = O(M*N)
//        dp[][]
// S.C. = O(M*N)
int minFallingPathSum_Tab(vector<vector<int>>& mat) {
    // code here
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    // filling base cases for first row
    for(int j = 0 ; j < n ; j++) {
        dp[0][j] = mat[0][j];
    }
    // now filling the dp[][] table
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i == 0) {
                dp[i][j] = mat[i][j];
            }
            else {
                int left = mat[i][j] + ((j-1 >= 0) ? dp[i-1][j-1] : 1e9);
                int up = mat[i][j] + dp[i-1][j];
                int right = mat[i][j] + ((j+1 < n) ? dp[i-1][j+1] : 1e9);
                dp[i][j] = min(left,min(up,right));
            }
        }
    }
    // answer will be the maximum value in the last row
    int mini = INT_MAX;
    for(int j = 0 ; j < n ; j++) {
        mini = min(mini,dp[m-1][j]);
    }
    return mini;
}

int main()
{
    return 0;
}