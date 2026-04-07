// Leetcode : 1903 (EASY)

// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

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
    string largestOddNumber(string num) {
        // we try to find the largest odd number
        // // 55 - 48 = 7
        for(int i = num.length()-1 ; i >= 0 ; i--) {
            if((num[i] - '0') & 1) {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};

int main()
{
    return 0;
}