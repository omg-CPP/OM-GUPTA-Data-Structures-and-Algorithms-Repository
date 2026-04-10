// Leetcode : 344 (EASY)

// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.

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

// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0;
        int hi = s.size()-1;
        while(lo < hi) {
            swap(s[lo],s[hi]);
            lo++;
            hi--;
        }
        return;
    }
};

int main()
{
    return 0;
}