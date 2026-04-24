// This is done to find Range Query Sum in O(sqrt(N)) time instead of O(N) time...
// When to use: when we have to improve brute force
// queries = Q
// T.C. = O(Q*N) :: Brute Force
// T.C. = O(Q*sqrt(N)) :: Optimal Approach

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

// function for sqrt decomposition
// T.C. = O(sqrt(N)) + O(sqrt(N)) + O(sqrt(N)) = O(sqrt(N))
// S.C. = O(ceil(sqrt(N)))
int rangeSumQuery(int L, int R, vector<int>& nums, vector<int>& blockSum) {
    int n = nums.size();
    int blockSize = ceil(sqrt(n));
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

int main()
{
    // dry run is important
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int blockSize = ceil(sqrt(nums.size()));
    vector<int> blockSum(blockSize,0);
    for(int i = 0 ; i < nums.size() ; i++) {
        blockSum[i/blockSize] += nums[i];
    }
    cout<<rangeSumQuery(0,2,nums,blockSum)<<endl; // 6
    cout<<rangeSumQuery(0,8,nums,blockSum)<<endl; // 45
    cout<<rangeSumQuery(1,7,nums,blockSum)<<endl; // 35
    cout<<rangeSumQuery(2,6,nums,blockSum)<<endl; // 25
    return 0;
}