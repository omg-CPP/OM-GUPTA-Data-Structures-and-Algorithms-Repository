// Leetcode : 1914 (MEDIUM)

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
    void reverseArray(int i, int j, vector<int>& nums) {
        while(i < j) {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }

    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        reverseArray(0,k-1,nums);
        reverseArray(k,n-1,nums);
        reverseArray(0,n-1,nums);
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // each layer requires 2 rows and 2 columns
        int layers = min(m/2,n/2);

        // traversing each layer
        for(int layer = 0 ; layer < layers ; layer++) {
            vector<int> nums;
            int top = layer;
            int bottom = m-1-layer;
            int left = layer;
            int right = n-1-layer;

            // top row :: left -> right
            for(int j = left ; j <= right ; j++) {
                nums.push_back(grid[top][j]);
            }

            // right column :: top -> bottom
            // skip corners as they are already included in top/ bottom rows
            for(int i = top+1 ; i <= bottom-1 ; i++) {
                nums.push_back(grid[i][right]);
            }

            // bottom row :: right -> left
            for(int j = right ; j >= left ; j--) {
                nums.push_back(grid[bottom][j]);
            }

            // left column :: bottom -> top
            // skip corners as they are already included in top/ bottom rows
            for(int i = bottom-1 ; i >= top+1 ; i--) {
                nums.push_back(grid[i][left]);
            }

            // now rotating the nums array
            int len = nums.size();
            int shift = k % len;
            rotateArray(nums,shift);
            
            // filling back to the grid
            int idx = 0;
            for(int j = left ; j <= right ; j++) {
                grid[top][j] = nums[idx++];
            }
            for(int i = top+1 ; i <= bottom-1 ; i++) {
                grid[i][right] = nums[idx++];
            }
            for(int j = right ; j >= left ; j--) {
                grid[bottom][j] = nums[idx++];
            }
            for(int i = bottom-1 ; i >= top+1 ; i--) {
                grid[i][left] = nums[idx++];
            }
        }
        return grid;
    }
};

int main()
{
    return 0;
}