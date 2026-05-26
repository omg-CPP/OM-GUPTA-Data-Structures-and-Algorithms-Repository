// Leetcode : 520 (EASY)

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
    bool detectCapitalUse(string word) {
        int n = word.length();
        int capitalCount = 0;
        // count uppercase letters
        for(char& ch : word) {
            if(ch >= 'A' && ch <= 'Z') capitalCount++;
        }

        // Case 1: all capitals
        if(capitalCount == n) return true;
        // Case 2: all lowercase
        else if(capitalCount == 0) return true;
        // Case 3: only first letter capital
        else if(capitalCount == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;
        // In all other cases
        else return false;
    }
};

int main()
{
    return 0;
}