// Leetcode : 2287 (EASY)

// You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.

// Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

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
    int rearrangeCharacters(string s, string target) {
        // Frequency of characters in s
        vector<int> freqS(26,0);

        // Count characters in s
        for(char& ch : s) {
            freqS[ch-'a']++;
        }

        // Frequency of characters required in target
        vector<int> freqT(26, 0);
        for(char& ch : target) {
            freqT[ch-'a']++;
        }

        // Find how many complete copies of target can be formed
        int ans = INT_MAX;
        for(int i = 0 ; i < 26 ; i++) {
            // Only consider characters that appear in target
            if(freqT[i] > 0) {
                ans = min(ans, freqS[i] / freqT[i]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}