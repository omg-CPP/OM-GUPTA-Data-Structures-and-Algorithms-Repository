// Leetcode : 3941 (MEDIUM)

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
// S.C. = O(N) :: set{}
class Solution {
public:
    int passwordStrength(string password) {
        // storing only unique characters of password
        unordered_set<char> st(password.begin(), password.end());
        int strength = 0;
        for(char ch : st) {
            if(ch >= 'a' && ch <= 'z') strength += 1;
            else if(ch >= 'A' && ch <= 'Z') strength += 2;
            else if(ch >= '0' && ch <= '9') strength += 3;
            else strength += 5;
        }
        return strength;
    }
};


int main()
{
    return 0;
}