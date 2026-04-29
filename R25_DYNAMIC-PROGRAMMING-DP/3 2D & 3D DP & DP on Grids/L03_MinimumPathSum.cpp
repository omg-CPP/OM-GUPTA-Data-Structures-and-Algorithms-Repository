// Leetcode : 64

#include <iostream>
#include <vector>
using namespace std;

// **************************** Memoization DP *********************************
// T.C. = O(N*M)
//       rec stack space   dp[][]
// S.C. = O(path length) + O(N*M)
//        O((m-1)+(n-1)) + O(N*M)
int fun_Mem(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // base cases
    if(r == 0 && c == 0) {
        return grid[r][c];
    }
    if(r < 0 || c < 0) {
        return 1e9;
    }
    // checking if there are overlapping sub-problems
    // i.e. if there is pre-computed values
    if(dp[r][c] != -1) {
        return dp[r][c];
    }
    int up = grid[r][c] + fun_Mem(r-1,c,grid,dp);
    int left = grid[r][c] + fun_Mem(r,c-1,grid,dp);
    return dp[r][c] = min(up,left);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return fun_Mem(m-1,n-1,grid,dp);
}

// **************************** Tabulation DP *********************************
// T.C. = O(N*M)
// S.C. = O(N*M)
int minPathSum_Tab(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0] = grid[0][0];
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[0][0];
            }
            else {
                int up = grid[i][j];
                if(i > 0) {
                    up += dp[i-1][j];
                }
                else {
                    up += 1e9;
                }
                int left = grid[i][j];
                if(j > 0) {
                    left += dp[i][j-1];
                }
                else {
                    left += 1e9;
                }
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    return 0;
}