// Leetcode : 3926 (MEDIUM)

// You are given an array of strings chunks. The strings are concatenated in order to form a single string s.
// You are also given an array of strings queries.

// A word is defined as a substring of s that:
// consists of lowercase English letters ('a' to 'z'),
// may include hyphens ('-') only if each hyphen is surrounded by lowercase English letters, and
// is not part of a longer substring that also satisfies the above conditions.
// Any character that is not a lowercase English letter or a valid hyphen acts as a separator.

// Return an integer array ans such that ans[i] is the number of occurrences of queries[i] as a word in s.
// A substring is a contiguous non-empty sequence of characters within a string.

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

// T.C. = O(N+M)
// S.C. = O(freq mp)
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        // Step 1: Concatenate all chunks to form the complete string s
        string s = "";
        for(string& part : chunks) {
            s += part;
        }

        // Step 2: Extract all valid words and count their frequencies
        unordered_map<string, int> freq;
        int i = 0;
        int n = s.size();
        while(i < n) {
            // Skip separator characters until we find a lowercase letter
            // this ensures starting a new valid word 
            if(!(s[i] >= 'a' && s[i] <= 'z')) {
                i++;
                continue;
            }

            // Start building a valid word
            string word;
            word += s[i];
            i++;

            // Continue while characters can legally belong to the word
            while(i < n) {
                // Lowercase letters are always allowed
                if(s[i] >= 'a' && s[i] <= 'z') {
                    word += s[i];
                    i++;
                }
                // Hyphen is allowed only if surrounded by lowercase letters
                else if(s[i] == '-' &&
                         i-1 >= 0 && (s[i-1] >= 'a' && s[i-1] <= 'z') &&
                         i+1 < n && (s[i+1] >= 'a' && s[i+1] <= 'z')) {
                    word += s[i];
                    i++;
                }
                // Any other character ends the current word
                else {
                    break;
                }
            }
            // Store the word frequency
            freq[word]++;
        }

        // Step 3: Answer each query
        vector<int> ans;
        for(string& q : queries) {
            ans.push_back(freq[q]);
        }
        return ans;
    }
};


int main()
{
    return 0;
}