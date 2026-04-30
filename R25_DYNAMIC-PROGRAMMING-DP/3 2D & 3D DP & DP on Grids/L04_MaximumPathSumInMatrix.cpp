// GFG

// You are given a matrix mat[][] of size n x m where each element is a positive integer. Starting from any cell in the first row, you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, you can move to any of the three possible positions :

// (r+1, c-1) — move diagonally to the left.
// (r+1, c) — move directly down.
// (r+1, c+1) — move diagonally to the right.
// Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.

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
        return INT_MIN;
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
    return dp[r][c] = max(left,max(up,right));
}

// Writing first the recursive code
int maximumPath(vector<vector<int>>& mat) {
    // code here
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    // as we can start from any column of the first row
    int maxi = INT_MIN;
    for(int j = 0 ; j < n ; j++) {
        maxi = max(maxi, solve(mat,m-1,j,dp));
    }
    return maxi;
}


// Writing the Tabulation DP code 
// T.C. = O(N) + O(M*N) + O(N) = O(M*N)
//        dp[][]
// S.C. = O(M*N)
int maximumPath_Tab(vector<vector<int>>& mat) {
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
                int left = mat[i][j] + ((j-1 >= 0) ? dp[i-1][j-1] : INT_MIN);
                int up = mat[i][j] + dp[i-1][j];
                int right = mat[i][j] + ((j+1 < n) ? dp[i-1][j+1] : INT_MIN);
                dp[i][j] = max(left,max(up,right));
            }
        }
    }
    // answer will be the maximum value in the last row
    int maxi = INT_MIN;
    for(int j = 0 ; j < n ; j++) {
        maxi = max(maxi,dp[m-1][j]);
    }
    return maxi;
}

int main()
{
    return 0;
}