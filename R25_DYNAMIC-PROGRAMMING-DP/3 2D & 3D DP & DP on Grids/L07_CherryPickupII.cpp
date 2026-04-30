// Leetcode : 1463 (3D DP)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Memoization DP
// T.C. = O(M*N*N)
//        dp[][][]  rec stack space
// S.C. = O(M*N*N) + O(M)
int fun_Mem(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    int m = grid.size();
    int n = grid[0].size();
    // out of bound cases
    if(i > m-1 || j1 < 0 || j1 > n-1 || j2 < 0 || j2 > n-1) {
        return INT_MIN;
    }
    if(i == m-1) {
        if(j1 == j2) {
            return grid[i][j1];
        }
        else { // j1 != j2
            return grid[i][j1] + grid[i][j2];
        }
    }
    // if pre-computed before
    if(dp[i][j1][j2] != -1) {
        return dp[i][j1][j2];
    }
    // explore all paths for roboI and roboII simultaneoulsy
    int maxi = INT_MIN;
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++) {
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++) {
            int value = 0;
            if(j1 == j2) {
                value = grid[i][j1];
            }
            else {
                value = grid[i][j1] + grid[i][j2];
            }
            value += fun_Mem(i+1,j1+dj1,j2+dj2,grid,dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    // dp[m][n][n] -> 3D DP
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));
    return fun_Mem(0,0,n-1,grid,dp);
}


// Tabulation DP
// T.C. = O(M*N*N) * 9
//        dp[][][]
// S.C. = O(M*N*N)
int cherryPickup_Tab(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    // dp[m][n][n] -> 3D DP
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,0)));
    // base cases
    for(int j1 = 0 ; j1 < n ; j1++) {
        for(int j2 = 0 ; j2 < n ; j2++) {
            if(j1 == j2) {
                dp[m-1][j1][j2] = grid[m-1][j1];
            }
            else { // j1 != j2
                dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
    }

    // filling the dp[][][] table
    for(int idx = m-2 ; idx >= 0 ; idx--) {
        for(int j1 = 0 ; j1 < n ; j1++) {
            for(int j2 = 0 ; j2 < n ; j2++) {
                int maxi = INT_MIN;
                for(int dj1 = -1 ; dj1 <= 1 ; dj1++) {
                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++) {
                        int value = 0;
                        if(j1 == j2) {
                            value = grid[idx][j1];
                        }
                        else { // j1 != j2
                            value = grid[idx][j1] + grid[idx][j2];
                        }
                        if(j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n) {
                            value += dp[idx+1][j1+dj1][j2+dj2];
                        }
                        else {
                            value += -1e9;
                        }
                        maxi = max(maxi, value);
                    }
                }
                dp[idx][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n-1];
}


int main()
{
    return 0;
}