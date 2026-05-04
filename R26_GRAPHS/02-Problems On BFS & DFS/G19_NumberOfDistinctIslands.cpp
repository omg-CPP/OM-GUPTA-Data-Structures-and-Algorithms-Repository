// Number of Distinct Islands :: Leetcode & GFG

#include <iostream>
#include <vector>
#include <set>
using namespace std;

//         for loop        dfs
// T.C. = N*M * log(N*M) + (N*M*4)
//        vis       set
// S.C. = O(N*M) + O(N*M)

void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid, vector<pair<int,int>>& vec, int row0, int col0) {
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = 1;
    vec.push_back({row-row0,col-col0});

    vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};

    for(auto& dir : directions) {
        int nRow = row + dir.first;
        int nCol = col + dir.second;
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1) {
            dfs(nRow,nCol,visited,grid,vec,row0,col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int,int>>> st;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                vector<pair<int,int>> vec;
                dfs(i,j,visited,grid,vec,i,j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main()
{
    return 0;
}
