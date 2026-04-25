// Leetcode : 2833 (EASY)

// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

// In the ith move, you can choose one of the following directions:

// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.

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
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, dash = 0;
        for(char& ch : moves) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else dash++;
        }
        return abs(left - right) + dash;
    }
};

int main()
{
    return 0;
}