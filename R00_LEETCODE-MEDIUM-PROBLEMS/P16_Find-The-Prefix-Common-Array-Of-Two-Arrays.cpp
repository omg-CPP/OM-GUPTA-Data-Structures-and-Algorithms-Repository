// Leetcode : 2567 (MEDIUM)

// You are given two 0-indexed integer permutations A and B of length n.

// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

// Return the prefix common array of A and B.

// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

// Example 1:

// Input: A = [1,3,2,4], B = [3,1,2,4]
// Output: [0,2,3,4]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
// At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

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

// Brute Force Approach
// T.C. = O(N^3)
// S.C. = O(1)
class Solution_1 {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n,0);

        for(int currIdx = 0 ; currIdx < n ; currIdx++) {
            int commonCount = 0;
            for(int aIdx = 0 ; aIdx <= currIdx ; aIdx++) {
                for(int bIdx = 0 ; bIdx <= currIdx ; bIdx++) {
                    // Check if elements match, and count if they do
                    if(A[aIdx] == B[bIdx]) {
                        commonCount++;
                        break;
                    }
                }
            }
            // Store the count of common elements for the current prefix
            prefixCommonArray[currIdx] = commonCount;
        }
        return prefixCommonArray;
    }
};


// Better Approach : Using HashSet
// T.C. = O(N^2)
// S.C. = O(N) + O(N) = O(N) : set{}
class Solution_2 {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n,0);
        unordered_set<int> elementsInA, elementsInB;

        // Iterate through the elements of both arrays
        for(int currIdx = 0 ; currIdx < n ; currIdx++) { // O(N)
            elementsInA.insert(A[currIdx]);
            elementsInB.insert(B[currIdx]);

            int commonCount = 0;
            // Count common elements between the sets
            for(int ele : elementsInA) { // O(N)
                if(elementsInB.count(ele)) { // O(1)
                    commonCount++;
                }
            }
            prefixCommonArray[currIdx] = commonCount;
        }
        return prefixCommonArray;
    }
};


// Optimal Approach : Single Pass with Frequency Array
// T.C. = O(N)
// S.C. = O(N) : freq[]
class Solution_3 {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n), freq(n+1,0);
        int common = 0;
        // Iterate through the elements of both arrays
        for(int currIdx = 0 ; currIdx < n ; currIdx++) {    

            // Add A[currIdx]
            freq[A[currIdx]]++;
            // If frequency becomes 2, this number has appeared in both arrays
            if(freq[A[currIdx]] == 2) common++;
                
            // Add B[currIdx]
            freq[B[currIdx]]++;
            // If frequency becomes 2, this number has appeared in both arrays
            if(freq[B[currIdx]] == 2) common++;

            prefixCommonArray[currIdx] = common;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};



int main()
{
    return 0;
}