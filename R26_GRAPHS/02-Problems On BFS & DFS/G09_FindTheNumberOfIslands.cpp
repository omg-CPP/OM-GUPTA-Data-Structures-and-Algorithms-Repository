// GFG : Find the number of Islands
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//         vis     queue
// S.C. = O(N^2) + O(N^2)
// 
// T.C. = O(N^2) + O(9*N^2)

void breadthFirstSearch(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& grid) {
    // grid with n rows and m columns
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
        for(int delRow = -1 ; delRow <= 1 ; delRow++) {
            for(int delCol = -1 ; delCol <= 1 ; delCol++) {
                int nRow = row + delRow;
                int nCol = col + delCol;
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 'L' && !visited[nRow][nCol]) {
                    visited[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
}

int countIslandsBFS(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    int cnt = 0;
    for(int row = 0 ; row < n ; row++) {
        for(int col = 0 ; col < m ; col++) {
            if(!visited[row][col] && grid[row][col] == 'L') {
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

    // traverse it's neighbours and mark them visited
    for(int delRow = -1 ; delRow <= 1 ; delRow++) {
        for(int delCol = -1 ; delCol <= 1 ; delCol++) {
            int nRow = r + delRow;
            int nCol = c + delCol;
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 'L' && !visited[nRow][nCol]) {
                depthFirstSearch(nRow,nCol,visited,grid);
            }
        }
    }
}

int countIslandsDFS(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Create visited matrix with same dimensions as grid
    vector<vector<int>> visited(n,vector<int>(m,0));
    int islandCount = 0;
    
    // Iterate through every cell in the grid
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            // If cell is land and not visited, we found a new island
            if(grid[row][col] == 'L' && !visited[row][col]) {
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
