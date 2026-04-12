// Check K-th Bit (GFG)

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

// Approach 1: using leftshift operator (<<)
// T.C. = O(1)
// S.C. = O(1)
bool checkKthBitI(int n, int k) {
    if((n & (1 << k)) != 0) {
        return true;
    }
    return false;
}

// Approach 2: using rightshift operator (>>)
// T.C. = O(1)
// S.C. = O(1)
bool checkKthBitII(int n, int k) {
    if(((n >> k) & 1) == 1) {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}