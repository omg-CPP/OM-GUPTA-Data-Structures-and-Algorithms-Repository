// Leetcode : 191 (EASY)

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

// brute force
int hammingWeightI(int n) {
    return __builtin_popcount(n);
}

// better approach
int hammingWeightII(int n) {
    int count = 0;
    while(n != 1) {
        if(n % 2 == 1) {
            count++;
        }
        n = n / 2;
    }
    count++;
    return count;
}

// optimal approach
// 13 -> 6 -> 3 -> 1
// 13 = 1101
//  6 = 0110
//  3 = 0011
//  1 = 0001
int hammingWeightIII(int n) {
    int count = 0;
    while(n != 1) {
        if(n & 1) { // n & 1 == 1
            count++;
        }
        n = n >> 1; // n = n / 2
    }
    count++;
    return count;
}


// most optimal
// N = 84

// 1st rightmost set bit
//   1 0 1 0 1 0 0
// & 1 0 1 0 0 1 1
//   1 0 1 0 0 0 0

// 2nd rightmost set bit
//   1 0 1 0 0 0 0
// & 1 0 0 1 1 1 1
//   1 0 0 0 0 0 0

// 3rd rightmost set bit
//   1 0 0 0 0 0 0
// & 0 1 1 1 1 1 1
//   0 0 0 0 0 0 0

// n = 0, loop breaks
// T.C. = O(noOfSetBits) = ~ O(log2(n) + 1) = O(31) -> worst case :: n = (2^31 - 1)
// S.C. = O(1)
int hammingWeightIIII(int n) {
    int count = 0;
    while(n != 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}


int main()
{
    return 0;
}