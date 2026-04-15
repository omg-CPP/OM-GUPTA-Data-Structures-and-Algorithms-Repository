// Leetcode : 2515 (EASY)

// You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

// Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
// Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

// Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

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
    // T.C. = O(N*L)
    // S.C. = O(1)
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            if(words[i] == target) { // string comparisons
                int straightDist = abs(i-startIndex);
                int circularDist = n-straightDist;
                minDist = min({minDist,straightDist,circularDist});
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};


int main()
{
    return 0;
}