// Leetcode : 1768 (EASY)

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
    // Two Pointers 
    // T.C. = O(max(len(word1),len(word2))
    // S.C. = O(1)
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int i = 0;
        int j = 0;
        while(i < word1.length() && j < word2.length()) {
            merged += word1[i++];
            merged += word2[j++];
        }
        while(i < word1.length()) {
            merged += word1[i++];
        }
        while(j < word2.length()) {
            merged += word2[j++];
        }
        return merged;
    }
};

int main()
{
    return 0;
}