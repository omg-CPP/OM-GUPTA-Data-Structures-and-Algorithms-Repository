// Leetcode : 2180 (EASY)

// Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

// The digit sum of a positive integer is the sum of all its digits.

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
    int countEven(int num) {
        int count = 0;
        for(int i = 1 ; i <= num ; i++) {
            int n = i;
            int sum = 0;
            while(n != 0) {
                sum += (n % 10);
                n /= 10;
            }
            count += (sum % 2 == 0);
        }
        return count;
    }
};

int main()
{
    return 0;
}