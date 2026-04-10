// Leetcode : 345 (EASY)

// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

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
// S.C. = O(1)
class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i < j) {
            if(isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i++],s[j--]);
            }
            else if(!isVowel(s[i]) && isVowel(s[j])) {
                i++;
            }
            else {
                j--;
            }
        }
        return s;
    }
};

int main()
{
    return 0;
}