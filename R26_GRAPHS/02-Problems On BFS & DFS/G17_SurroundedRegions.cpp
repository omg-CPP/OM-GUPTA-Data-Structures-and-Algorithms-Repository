// Leetcode : 130

#include <iostream>
#include <vector>
using namespace std;

// 0 0 0 
// 0 0 0
// 0 0 0
// T.C. = O(N) + O(N) + O(N*M * 4)
//       visited   rec stack space
// S.C. = O(N*M) + O(N*M)

void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    visited[row][col] = 1;
    // visiting neighbours
    vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    for(auto& dir : directions) {
        int nRow = row + dir.first;
        int nCol = col + dir.second;
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && board[nRow][nCol] == 'O') {
            dfs(nRow,nCol,visited,board);
        }
    }
}


void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    // traverse the first row and last row
    for(int j = 0 ; j < m ; j++) {
        // first row
        if(!visited[0][j] && board[0][j] == 'O') {
            dfs(0,j,visited,board);
        }
        // last row
        if(!visited[n-1][j] && board[n-1][j] == 'O') {
            dfs(n-1,j,visited,board);
        }
    }

    // traverse the first column and last column
    for(int i = 0 ; i < n ; i++) {
        // first column
        if(!visited[i][0] && board[i][0] == 'O') {
            dfs(i,0,visited,board);
        }
        // last column
        if(!visited[i][m-1] && board[i][m-1] == 'O') {
            dfs(i,m-1,visited,board);
        }
    }


    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(!visited[i][j] && board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}


int main()
{
    return 0;
}
