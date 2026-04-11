// Leetcode : 304 (MEDIUM)

// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cmath>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    // construction of prefixSum Grid : O(M*N)
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        prefixSum.assign(m,vector<int>(n,0));
        // filling the prefixSum Grid
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                prefixSum[i][j] = matrix[i][j];
                // adding from top
                if(i > 0) prefixSum[i][j] += prefixSum[i-1][j];
                // adding from left
                if(j > 0) prefixSum[i][j] += prefixSum[i][j-1];
                // subtracting overlapping region
                if(i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
            }
        }
    }

    // Return sum of elements inside the given rectangle : O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = prefixSum[row2][col2];
        if(row1 > 0) result -= prefixSum[row1-1][col2];
        if(col1 > 0) result -= prefixSum[row2][col1-1];
        if(row1 > 0 && col1 > 0) result += prefixSum[row1-1][col1-1];
        return result;
    }
};


int main()
{
    return 0;
}