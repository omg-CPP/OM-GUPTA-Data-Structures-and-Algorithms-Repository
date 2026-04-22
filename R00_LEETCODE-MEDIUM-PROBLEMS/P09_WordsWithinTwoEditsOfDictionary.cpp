// Leetcode : 2452 (MEDIUM)

// You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

// In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

// Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

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
    // T.C. = O(Q * M * N)
    // S.C. = O(1)
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(string& query : queries) {
            for(string& dict : dictionary) {
                int diff = 0;
                // query.length() == dict.length()
                for(int i = 0 ; i < query.length() ; i++) {
                    if(query[i] != dict[i]) {
                        diff++;
                    }
                    if(diff > 2) break;
                }
                if(diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}