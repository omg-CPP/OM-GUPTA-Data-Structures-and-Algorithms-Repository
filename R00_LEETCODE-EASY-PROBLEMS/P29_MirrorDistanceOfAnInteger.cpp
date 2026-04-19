// Leetcode : 3783 (EASY)

// You are given an integer n.
// Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.
// Return an integer denoting the mirror distance of n​​​​​​​.
// abs(x) denotes the absolute value of x.

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
    int reverse(int n) {
        int rev = 0;
        while(n > 0) {
            rev = (rev*10) + (n%10);
            n /= 10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};

int main()
{
    return 0;
}

