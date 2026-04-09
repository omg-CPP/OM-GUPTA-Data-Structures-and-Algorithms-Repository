// Leetcode : 1688 (EASY)

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
    // T.C. = O(log2(n)) :: n -> n/2 -> n/4 -> ---- -> 1
    // S.C. = O(1)
    int numberOfMatches(int n) {
        int matches = 0;
        while(n > 1) {
            if(n & 1) { // odd no of teams
                matches += (n-1) / 2;
                n = (n-1) / 2 + 1;
            }
            else { // no of teams are even
                matches += n / 2;
                n = n / 2;
            }
        }
        return matches;
    }

    // optimal O(1) soln
    int numberOfMatches_(int n) {
        // total teams = n
        // winner = 1
        // eliminated = n-1
        // 1 match :: 1 win & 1 lose
        // n-1 eliminate : n-1 matches
        return n-1;
    }
};

int main()
{
    return 0;
}

// m = 3 + 1 + 1 = 4
// 6 teams
// 3 matches = 3 winners 3 loser
// 1 match = 1 winner 1 loser
// 1 match = 1 winner