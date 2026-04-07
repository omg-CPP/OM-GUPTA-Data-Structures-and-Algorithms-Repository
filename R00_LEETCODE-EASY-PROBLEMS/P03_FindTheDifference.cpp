// Leetcode : 389 (EASY)

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
    // approach 1: using extra space
    // T.C. = O(N)
    // S.C. = O(N)
    char findTheDifference_I(string s, string t) {
        vector<int> count(26,0);
        for(char& ch : s) {
            count[ch-'a']++;
        }
        for(char& ch : t) {
            count[ch-'a']--;
        }
        for(int i = 0 ; i < 26 ; i++) {
            if(count[i] == -1) {
                return char(i + 'a');
            }
        }
        return 'a'; // returning a random value, this line never gets executed
    }

    // approach 2: using sum of ascii values
    // T.C. = O(N)
    // S.C. = O(1)
    char findTheDifference_II(string s, string t) {
        int sum1 = 0;
        for(char& ch : s) {
            sum1 += (int)ch;
        }
        int sum2 = 0;
        for(char& ch : t) {
            sum2 += (int)ch;
        }
        return char(sum2-sum1);
    }

    // approach 3: using XOR
    // T.C. = O(N)
    // S.C. = O(1)
    char findTheDifference_III(string s, string t) {
        int xorr = 0;
        for(char& ch : s) {
            xorr ^= ch;
        }
        for(char& ch : t) {
            xorr ^= ch;
        }
        return (char)xorr;
    }

};


int main()
{
    return 0;
}