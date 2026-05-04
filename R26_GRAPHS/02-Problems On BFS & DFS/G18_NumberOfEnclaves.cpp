// Leetcode : 1020

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// all peices are land
// 1 1 1
// 1 1 1
// 1 1 1
// T.C. = O(N*M) + O(N*M * 4)
// S.C. = O(N*M) + O(N*M)

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto& dir : directions) {
            int nRow = row + dir.first;
            int nCol = col + dir.second;
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1) {
                q.push({nRow,nCol});
                visited[nRow][nCol] = 1;
            }
        }
    }

    int enclaves = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                enclaves++;
            }
        }
    }
    return enclaves;
}

int main()
{
    return 0;
}
