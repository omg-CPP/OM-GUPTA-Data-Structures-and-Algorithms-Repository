// Toggle the K-th Bit
// k-th bit = 0 -> kth bit = 1
// k-th bit = 1 -> kth bit = 0

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

// Approach 1: using clear kth bit concept
// T.C. = O(1)
// S.C. = O(1)
int toggleBitI(int n, int k) {
    // if the k-th bit is 1, kth bit = 1
    if((n & (1 << k)) != 0) {
        n = n & (~(1 << k));
    }
    else { // (n & (1 << k)) == 0, kth bit = 0
        n = n | (1 << k);
    }
    return n;
}

// Approach 2: using XOR (^)
// T.C. = O(1)
// S.C. = O(1)
int toggleBitII(int n, int k) {
    return (n ^ (1 << k));
}

int main()
{
    int n = 13;
    int k = 2;
    cout<<toggleBitI(n,k)<<endl; // 9
    cout<<toggleBitII(n,k)<<endl; // 9
    return 0;
}