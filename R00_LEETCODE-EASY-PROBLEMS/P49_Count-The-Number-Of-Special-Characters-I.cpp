// Leetcode : 3120 (EASY)

// You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
// Return the number of special letters in word.

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

// T.C. = O(N) + O(26)
// S.C. = O(26)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<pair<int,int>> freq(26,{0,0});
        for(int i = 0 ; i < n ; i++) {
            // lowercase
            if(word[i] >= 'a' && word[i] <= 'z') {
                freq[word[i]-'a'].first += 1;
            }
            else { // uppercase -> word[i] >= 'A' && word[i] <= 'Z'
                freq[word[i]-'A'].second += 1;
            }
        }

        int specials = 0;
        for(int i = 0 ; i < 26 ; i++) {
            if(freq[i].first > 0 && freq[i].second > 0) {
                specials++;
            }
        }
        return specials;
    }
};

int main()
{
    return 0;
}

