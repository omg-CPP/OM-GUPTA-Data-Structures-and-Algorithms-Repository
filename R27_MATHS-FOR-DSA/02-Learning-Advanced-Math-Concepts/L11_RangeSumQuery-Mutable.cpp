// Leetcode : 307 (MEDIUM)
// Based on Sqrt Decomposition Approach

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

class NumArray {
public:
    vector<int> nums;
    vector<int> blockSum;
    int n;
    int blockSize;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        blockSize = ceil(sqrt(n));
        blockSum.resize(blockSize,0);
        // building the blockSum array
        for(int i = 0 ; i < n ; i++) {
            blockSum[i/blockSize] += nums[i];
        }
    }
    // O(1)
    void update(int index, int val) {
        int blockIdx = index / blockSize;
        blockSum[blockIdx] -= nums[index];
        blockSum[blockIdx] += val;
        nums[index] = val;
    }
    // O(sqrt(N))
    int sumRange(int L, int R) {
        int startBlock = L / blockSize;
        int endBlock = R / blockSize;
        // case 1: L & R are in same block
        int sum = 0;
        if(startBlock == endBlock) {
            // as if they are in same block, blockSize is sqrt(N), which is fine
            // O(sqrt(N))
            for(int i = L ; i <= R ; i++) {
                sum += nums[i];
            }
        }
        // case 2: L & R are in different blocks
        else {
            // left :: O(sqrt(N))
            // start of (start+1)th block = (startBlock+1) * blockSize
            int endOfStartBlock = ((startBlock+1) * blockSize) - 1;
            for(int i = L ; i <= endOfStartBlock ; i++) {
                sum += nums[i];
            }
            // middle :: O(sqrt(N))
            for(int i = startBlock+1 ; i <= endBlock-1 ; i++) {
                sum += blockSum[i];
            }
            // right :: O(sqrt(N))
            int startOfEndBlock = endBlock * blockSize;
            for(int i = startOfEndBlock ; i <= R ; i++) {
                sum += nums[i];
            }
        }
        return sum;
    }
};

int main()
{
    return 0;
}