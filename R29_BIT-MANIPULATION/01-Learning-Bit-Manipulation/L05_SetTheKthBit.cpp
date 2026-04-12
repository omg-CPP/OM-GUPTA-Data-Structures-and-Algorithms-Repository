// Set the Kth Bit to 1

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

// using leftshift operator (<<)
// T.C. = O(1)
// S.C. = O(1)
int setKthBit(int n, int k) {
    return (n | (1 << k));
}


int main()
{
    return 0;
}