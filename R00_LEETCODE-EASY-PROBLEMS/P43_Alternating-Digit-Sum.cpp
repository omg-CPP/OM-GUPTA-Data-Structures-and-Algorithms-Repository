// Leetcode : 2544 (EASY)

// You are given a positive integer n. Each digit of n has a sign according to the following rules:

// The most significant digit is assigned a positive sign.
// Each other digit has an opposite sign to its adjacent digits.
// Return the sum of all digits with their corresponding sign.

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
    // LSB will be -ve signed, digits are even
    // LSB will be +ve signed, digits are odd
    int alternateDigitSum(int n) {
        int digits = floor(log10(n)) + 1;
        int sign = (digits % 2) ? 1 : -1; 
        long long sum = 0;
        while(n != 0) {
            sum += ((sign) * (n % 10));
            n /= 10;
            sign = -sign;
        }
        return sum;
    }
};

int main()
{
    return 0;
}