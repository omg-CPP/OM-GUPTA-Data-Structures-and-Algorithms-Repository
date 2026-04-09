// Leetcode : 2264 (EASY)

// You are given a string num representing a large integer. An integer is good if it meets the following conditions:

// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.

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
    string largestGoodInteger(string num) {
        char maxChar = ' '; // ascii of space = 32
        // digits ascii -> 48-57
        for(int i = 2 ; i < num.length() ; i++) {
            // 3 len ka substring of only 1 unique digit
            if(num[i] == num[i-1] && num[i] == num[i-2]) {
                maxChar = max(maxChar,num[i]);
            }
        }
        if(maxChar == ' ') return "";
        return string(3,maxChar);
    }
};


int main()
{
    return 0;
}