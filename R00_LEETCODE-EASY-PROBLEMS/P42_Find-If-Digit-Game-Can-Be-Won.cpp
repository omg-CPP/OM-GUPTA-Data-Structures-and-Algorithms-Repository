// Leetcode : 3232 (EASY)

// You are given an array of positive integers nums.

// Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.

// Return true if Alice can win this game, otherwise, return false.

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
    bool canAliceWin(vector<int>& nums) {
        int sum_single = 0, sum_double = 0;
        for(int& x : nums) {
            if(x >= 0 && x <= 9) { // single digit number
                sum_single += x;
            }
            else { // double digit number
                sum_double += x;
            }
        }
        // idea is when the both sum's are different, Alice could take the bigger one and win...
        return sum_single != sum_double ? true : false;
    }
};

int main()
{
    return 0;
}