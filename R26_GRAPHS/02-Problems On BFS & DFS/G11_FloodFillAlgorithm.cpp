// Leetcode : 733

#include <iostream>
#include <vector>
using namespace std;

// worst case
// newColor = 2
// 0 0 0 
// 0 0 0 
// 0 0 0

// X = N*M
//       dfs call   each call neighbour
// T.C. = O(X)   +   O(X*4) = O(N*M)

//        extra matrix       rec stack space
// S.C. = O(N*M)         +       O(N*M) 



void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int initialColor, int newColor) {
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;
    // checks for its neighbours
    vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    for(auto dir : directions) {
        int nRow = row + dir.first;
        int nCol = col + dir.second;
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == initialColor && ans[nRow][nCol] != newColor) {
            dfs(nRow,nCol,ans,image,initialColor,newColor);
        }
    }
}

// DFS Solution
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image;
    // changes are done only to ans vector not the image
    dfs(sr,sc,ans,image,initialColor,color);
    return ans;
}


int main()
{
    vector<int> v1 = {1,2,3};
    vector<int> v2 = v1;
    v2.push_back(4);
    for(auto it : v1) {
        cout<<it<<" ";
    }
    // 1 2 3 
    cout<<endl;
    for(auto it : v2) {
        cout<<it<<" ";
    }
    // 1 2 3 4 
    return 0;
}
