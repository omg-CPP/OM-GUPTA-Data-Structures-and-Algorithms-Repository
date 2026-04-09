// Leetcode : 202 (EASY)

// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.


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
    //⚡ Key Insight
    // A number is:
    // ✅ Happy → reaches 1
    // ❌ Not Happy → falls into a cycle
    // we detect the number using cycle and store it in a set
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            int sum = 0;
            while(n > 0) {
                sum += ((n % 10) * (n % 10));
                n /= 10;
            }
            n = sum;
        }
        return n == 1 ? true : false;
    }
};

int main()
{
    return 0;
}