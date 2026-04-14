// Leetcode : 2220 (EASY)
// start and goal >= 0
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
    // T.C. = O(32) = O(1)
    // S.C. = O(1)
    int minBitFlipsI(int start, int goal) {
        int ans =  start ^ goal;
        // both numbers are same
        if(ans == 0) return 0;
        // now find set bits in ans
        int flips = 0;
        // 31st bit is a signed bit
        // 0 <= start, goal <= 10^9
        // as start and goal >= 0, 31st bit of both numbers must be 0 -> +ve
        // so we could only check till 30th bit
        for(int i = 0 ; i < 31 ; i++) {
            if(ans & (1 << i)) { // if the bit is a set bit
                flips++;
            }
        }
        return flips;
    }

    // T.C. = O(log2(ans) + 1), ans = start ^ goal
    // S.C. = O(1)
    int minBitFlipsII(int start, int goal) {
        int ans = start ^ goal;
        // both numbers are same
        if(ans == 0) return 0;
        // we need to find set bits in ans
        int flips = 0;
        while(ans != 1) {
            if(ans & 1) { // if ans is odd number i.e. LSB is 1
                // adding all remainders = 1
                flips++;
            }
            ans = ans >> 1;
        }
        // adding 1, which is the last quotient
        flips++;
        return flips;
    }
};


int main()
{
    return 0;
}