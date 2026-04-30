// Leetcode : 120

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

#include <iostream>
#include <vector>
using namespace std;

// Memoization DP
// T.C. = O(M*M)
//        dp[][]  rec stack space (path) -> No of rows
// S.C. = O(M*M) + O(M)
int fun_Mem(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    int m = triangle.size();
    // base case
    if(r == m-1) {
        return triangle[r][c];
    }
    // if pre-computed
    if(dp[r][c] != -1) {
        return dp[r][c];
    }
    // exploring all paths
    int down = triangle[r][c] + fun_Mem(r+1,c,triangle,dp);
    int rightDiag = triangle[r][c] + fun_Mem(r+1,c+1,triangle,dp);
    return dp[r][c] = min(down,rightDiag);
}

int minimumTotal(vector<vector<int>>& triangle) {
    // No of rows
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m,-1));
    return fun_Mem(0,0,triangle,dp);
}

// Tabulation DP
// T.C. = O(M*M)
//        dp[][]
// S.C. = O(M*M) 
int minimumTotal_Tab(vector<vector<int>>& triangle) {
    // No of rows
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m,-1));
    // handling the base cases
    for(int j = 0 ; j < m ; j++) {
        dp[m-1][j] = triangle[m-1][j];
    }
    // filling the dp[][]
    for(int i = m-2 ; i >= 0 ; i--) {
        for(int j = i ; j >= 0 ; j--) {
            int down = triangle[i][j] + dp[i+1][j];
            int rightDiag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,rightDiag);
        }
    }
    return dp[0][0];
}

// Space Optimisation

int main()
{
    return 0;
}