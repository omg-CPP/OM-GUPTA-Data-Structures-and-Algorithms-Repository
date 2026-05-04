// Leetcode : 542
// Distance of nearest cell having 1 :: GFG

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// T.C. = O(N∗M)
// S.C. = O(N∗M)
vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>> q;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(grid[i][j] == 0) {
                q.push({{i,j},0});
                visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};

        for(auto& dir : directions) {
            int nRow = row + dir.first;
            int nCol = col + dir.second;
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] == 0) {
                visited[nRow][nCol] = 1;
                q.push({{nRow,nCol},steps+1});
            }
        }
    }
    return dist;
}


int main()
{
    return 0;
}
