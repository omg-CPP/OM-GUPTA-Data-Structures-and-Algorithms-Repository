// Leetcode : 3121 (MEDIUM)

// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

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
        vector<pair<int,int>> occurrences(26,{-1,-1});
        for(int i = 0 ; i < n ; i++) {
            // lowercase
            if(word[i] >= 'a' && word[i] <= 'z') {
                // overiding again and again occurence of lowercase letter
                occurrences[word[i] - 'a'].first = i;
            }
            // uppercase
            else { // word[i] >= 'A' && word[i] < 'Z'
                // updating only for first occurence
                if(occurrences[word[i] - 'A'].second == -1) {
                    occurrences[word[i] - 'A'].second = i;
                }
            }
        }

        // Now try checking 
        int specials = 0;
        for(int i = 0 ; i < 26 ; i++) {
            int lower = occurrences[i].first;
            int upper = occurrences[i].second;
            if(lower != -1 && upper != -1 && lower < upper) {
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