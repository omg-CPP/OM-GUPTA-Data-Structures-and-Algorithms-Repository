// Leetcode : 190 (EASY)

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

// T.C. = O(32) = O(1)
// S.C. = O(1)
int reverseBits(int n) {
    if(n == 0) return 0;
    int ans = 0;
    // we have to reverse the entire 32 bit integer
    for(int i = 0 ; i <= 31 ; i++) {
        ans = ans << 1; // left shift to make space for lsb
        ans = (ans | (n & 1)); // pushing lsb to ans
        n = n >> 1; // rightshift the number
    }
    return ans;
}

int main()
{
    int n = 43261596;
    cout<<reverseBits(n)<<endl; // 964176192
    return 0;
}