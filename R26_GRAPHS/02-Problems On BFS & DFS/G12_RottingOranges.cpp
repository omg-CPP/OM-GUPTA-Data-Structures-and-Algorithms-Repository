// Leetcode : 994

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//        queue   visited
// S.C. = O(N*M) + O(N*M)
//        first loop bfs   each call neighbour
// T.C. = O(N*M) + O(N*M) + O(4*(N*M))

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // {{r,c},t}
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,0));
    int cntFresh = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(grid[i][j] == 2) {
                q.push({{i,j},0});
                visited[i][j] = 2;
            }
            if(grid[i][j] == 1) {
                cntFresh++;
            }
        }
    }

    int time = 0;
    int cnt = 0;
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;

        int t = q.front().second;
        time = max(time,t);
        q.pop();

        // checks for its neighbours
        vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto dir : directions) {
            int nRow = r + dir.first;
            int nCol = c + dir.second;
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && visited[nRow][nCol] != 2) {
                q.push({{nRow,nCol},t+1});
                visited[nRow][nCol] = 2;
                cnt++;
            }
        }
    }
    if(cnt != cntFresh) {
        return -1;
    }
    return time;
}


int main()
{
    return 0;
}
