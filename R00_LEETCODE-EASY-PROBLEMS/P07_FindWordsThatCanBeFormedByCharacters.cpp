// Leetcode : 1160 (EASY)

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

// m -> words.size(), n -> word.size()
// T.C. = O(chars.length()) + O(m*n)
// S.C. = O(32) = ~O(1)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        vector<int> count(26,0);
        for(char& ch : chars) {
            count[ch-'a']++;
        }

        int result = 0;
        for(string& word : words) {
            vector<int> wordCount(26,0);
            for(char& ch : word) {
                wordCount[ch-'a']++;
            }

            bool ok = true;
            for(int i = 0 ; i < 26 ; i++) {
                if(wordCount[i] > count[i]) {
                    ok = false;
                    break;
                }
            }
            if(ok == true) result += word.length();
        }
        return result;
    }
};

int main()
{
    return 0;
}