// Leetcode : 1189 (EASY)

// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

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
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26,0);

        // Count frequencies
        for(char& ch : text) {
            freq[ch-'a']++;
        }

        // Minimum number of times "balloon" can be formed
        return min({freq['b'-'a'], freq['a'-'a'], freq['l'-'a'] / 2, freq['o'-'a'] / 2, freq['n'-'a']});
    }
};

int main()
{
    return 0;
}