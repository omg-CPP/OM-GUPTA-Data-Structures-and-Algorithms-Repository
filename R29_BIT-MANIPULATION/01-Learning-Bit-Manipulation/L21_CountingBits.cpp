// Leetcode : 338 (EASY)

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
    // 1. brute force: using builtin function
    // T.C. = O(n)
    // S.C. = O(1)
    vector<int> countBitsI(int n) {
        vector<int> nums(n+1);
        for(int i = 0 ; i < n+1 ; i++) {
            nums[i] = __builtin_popcount(i); // O(1)
        }
        return nums;
    }

    // O(digits in binary representation) = O(log2(n) + 1)
    int findSetBits(int num) {
        if(num == 0) return 0;
        int cnt = 0;
        while(num != 1) {
            if(num & 1) { // last bit is 1
                cnt++;
            }
            num = num >> 1;
        }
        cnt++; // adding last left out 1
        return cnt;
    }

    // 2. another way: writing the __builtin_popcount(n) function
    // T.C. = O(n*logn)
    // S.C. = O(1)
    vector<int> countBitsII(int n) {
        vector<int> nums(n+1);
        for(int i = 0 ; i < n+1 ; i++) {
            nums[i] = findSetBits(i);
        }
        return nums;
    }


    // 3. optimal way: using Tabulation DP
    // T.C. = O(n)
    // S.C. = O(1)
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> nums(n+1);
        // base cases
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 2 ; i < n+1 ; i++) {
            if(i & 1) { // odd number
                nums[i] = nums[i/2] + 1;
            }
            else { // even number
                nums[i] = nums[i/2];
            }
        }
        return nums;
    }
};



int main()
{
    return 0;
}