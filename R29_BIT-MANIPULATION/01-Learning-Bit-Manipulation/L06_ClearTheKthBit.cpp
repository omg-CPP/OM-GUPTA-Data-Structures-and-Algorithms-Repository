// Clear the K-th Bit

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

// LSB
// clear kth bit from the right (0-based-indexing)
int replaceBit_Right(int n, int k) {
    return (n & (~(1 << k)));
}

// MSB
// clear kth bit from the left (1-based-indexing)
int replaceBit_Left(int n, int k) {
    // total bits in n
    int totalBits = floor(log2(n)) + 1;

    // position from right (0-based)
    int pos = totalBits - k;

    // check if that bit is 1
    if((n & (1 << pos)) != 0) {
        // clear it
        n = n & (~(1 << pos));
    }
    return n;
}

int main()
{
    return 0;
}