// Leetcode : 63

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
    if(r >= 0 && c >= 0 && grid[r][c] == 1) {
        return 0;
    }
    if(r == 0 && c == 0) {
        return 1;
    }
    if(r < 0 || c < 0) {
        return 0;
    }
    // checking if there are overlapping sub-problems
    // i.e. if there is pre-computed values
    if(dp[r][c] != -1) {
        return dp[r][c];
    }
    int up = fun_Mem(r-1,c,grid,dp);
    int left = fun_Mem(r,c-1,grid,dp);
    return dp[r][c] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    int totalWays = fun_Mem(m-1,n-1,obstacleGrid,dp);
    return totalWays;
}

// **************************** Tabulation DP *********************************
// T.C. = O(N*M)
// S.C. = O(N*M)
int uniquePathsWithObstacles_Tab(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0] = 1;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }
            else if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else {
                int up = 0;
                int left = 0;
                if(i > 0) {
                    up = dp[i-1][j];
                }
                if(j > 0) {
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    return 0;
}