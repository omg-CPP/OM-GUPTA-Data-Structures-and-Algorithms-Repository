// Leetcode : 29 (MEDIUM)

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
    int divide(int dividend, int divisor) {
        // base cases
        if(dividend == divisor) return 1;
        if(dividend == 0) return 0;
        
        bool sign = true; // it means +ve
        if(dividend < 0 && divisor > 0) sign = false; // it means -ve 
        if(dividend > 0 && divisor < 0) sign = false; // it means -ve

        long long p = abs(1LL*dividend);
        long long q = abs(1LL*divisor);
        long long quotient = 0;

        while(p >= q) {
            int cnt = 0;
            while(p >= (q << (cnt+1))) {
                cnt++;
            }
            quotient += (1 << cnt);
            p -= (q << cnt);
        }

        // overflows handling
        // INT_MAX = 2^31 - 1, INT_MIN = -2^31
        if(sign == true && quotient == (1 << 31)) return INT_MAX;
        if(sign == false && quotient == (1 << 31)) return INT_MIN;
        if(sign == false) quotient *= -1;
        return (int)quotient;
    }
};

int main()
{
    return 0;
}