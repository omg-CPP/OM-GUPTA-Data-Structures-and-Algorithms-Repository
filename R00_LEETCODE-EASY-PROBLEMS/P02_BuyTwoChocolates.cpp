// Leetcode : 2706 (EASY)

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
    // brute force: sorting & check first two chocolates prize
    // optimal: find mini and sec_mini
    // T.C. = O(N)
    // S.C. = O(1)
    int buyChoco(vector<int>& prices, int money) {
        int mini = INT_MAX;
        int sec_mini = INT_MAX;
        for(int& p : prices) {
            if(mini > p) {
                sec_mini = mini;
                mini = p;
            }
            else if(sec_mini > p) { 
                sec_mini = p;
            }
        }
        if(mini + sec_mini <= money) {
            return money - (mini + sec_mini); // leftover
        }
        return money;
    }
};

int main()
{
    return 0;
}