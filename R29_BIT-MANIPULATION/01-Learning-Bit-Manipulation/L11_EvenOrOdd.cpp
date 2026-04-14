// Even Or Odd :: GFG
// Given a positive integer n, determine whether it is odd or even. Return true if the number is even and false if the number is odd.

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
bool isEven(int n) {
    // code here
    if((n & 1) == 0) {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}