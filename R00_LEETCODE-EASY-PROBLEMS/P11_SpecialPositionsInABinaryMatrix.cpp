// Leetcode : 1582 (EASY)

// Given an m x n binary matrix mat, return the number of special positions in mat.
// A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

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

class Solution {
public:
    // Brute Force:
    // T.C. = O(M*N*(M+N))
    // S.C. = O(1)
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(mat[i][j] == 0) continue;
                // mat[i][j]
                if(mat[i][j] == 1) {
                    bool flag = true;
                    // checking in that row 
                    for(int c = 0 ; c < n ; c++) {
                        if(c == j) continue;
                        if(mat[i][c] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        // checking in that column
                        for(int r = 0 ; r < m ; r++) {
                            if(r == i) continue;
                            if(mat[r][j] == 1) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag) count++;
                }
            }
        }
        return count;
    }


    // Optimal: using extra space
    // T.C. = O(M*N) + O(M*N) = O(M*N)
    // S.C. = O(M+N)
    int numSpecial_Optimal(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        // storing data
        vector<int> rowOnes(m,0);
        vector<int> colOnes(n,0);
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(mat[i][j] == 1) {
                    rowOnes[i] += 1;
                    colOnes[j] += 1;
                }
            }
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(mat[i][j] == 0) continue;
                if(mat[i][j] == 1) {
                    if(rowOnes[i] == 1 && colOnes[j] == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};


int main()
{
    return 0;
}