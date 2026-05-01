// Leetcode 200

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void breadthFirstSearch(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    visited[r][c] = 1;
    queue<pair<int,int>> q;
    q.push({r,c});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // traverse it's neighbours and mark them visited

        // Check only 4 directions: up, down, left, right
        vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
        
        for(auto dir : directions) {
            int nRow = row + dir.first;
            int nCol = col + dir.second;
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !visited[nRow][nCol]) {
                visited[nRow][nCol] = 1;
                q.push({nRow,nCol});
            }
        }
    }
}

int numIslandsBFS(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    int cnt = 0;
    for(int row = 0 ; row < n ; row++) {
        for(int col = 0 ; col < m ; col++) {
            if(!visited[row][col] && grid[row][col] == '1') {
                cnt++;
                breadthFirstSearch(row,col,visited,grid);
            }
        }
    }
    return cnt;
}


// ************************* DFS *************************

void depthFirstSearch(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Mark current cell as visited
    visited[r][c] = 1;
    
    // Check only 4 directions: up, down, left, right
    vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    
    // Explore all 4 neighbors
    for(auto dir : directions) {
        int nRow = r + dir.first;
        int nCol = c + dir.second;
        
        // Check if the neighbor is within bounds, is land, and not visited
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !visited[nRow][nCol]) {
            depthFirstSearch(nRow,nCol,visited,grid);
        }
    }
}

int numIslandsDFS(vector<vector<char>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    
    // Create visited matrix with same dimensions as grid
    vector<vector<int>> visited(n,vector<int>(m,0));
    int islandCount = 0;
    
    // Iterate through every cell in the grid
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            // If cell is land and not visited, we found a new island
            if(grid[row][col] == '1' && !visited[row][col]) {
                islandCount++;
                depthFirstSearch(row,col,visited,grid);
            }
        }
    }
    return islandCount;
}

int main()
{
    return 0;
}
