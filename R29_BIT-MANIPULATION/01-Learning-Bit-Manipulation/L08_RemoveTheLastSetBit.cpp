// Clear or remove the last set bit (rightmost)
// Turn off the rightmost set bit

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

// T.C. = O(1)
// S.C. = O(1)
int removeLastSetBit(int n) {
    return (n & (n-1));
}

int main()
{
    int n = 84;
    cout<<removeLastSetBit(n)<<endl; // 80
    return 0;
}