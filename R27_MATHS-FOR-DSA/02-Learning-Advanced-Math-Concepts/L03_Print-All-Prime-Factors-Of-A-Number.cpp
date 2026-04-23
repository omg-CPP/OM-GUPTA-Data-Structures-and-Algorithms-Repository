// Print all prime factors of a number
// Given a number n. Find its unique prime factors in increasing order.
// GFG

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
    // Brute Force Approach
    // T.C. = O(N*sqrt(N))
    // S.C. = O(1)
    bool isPrime(int n) {
        if(n == 1) return false;
        int count = 0;
        for(int i = 1 ; i*i <= n ; i++) {
            if(n % i == 0) {
                count += 1;
                if(n/i != i) {
                    count += 1;
                }
            }
            if(count > 2) return false; // meaning composite
        }
        // count == 2
        return true; // meaning prime
    }

    vector<int> primeFactors_I(int n) {
        vector<int> result;
        for(int i = 2 ; i <= n ; i++) {
            // check if i is a factor
            if(n % i == 0) {
                // check if the factor is prime
                if(isPrime(i)) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }

    // ***************************************
    // Better Approach
    // T.C. ~= O(sqrt(N) * 2 * sqrt(N)) - approximate
    // S.C. = O(1)
    vector<int> primeFactors_II(int n) {
        vector<int> result;
        for(int i = 1 ; i*i <= n ; i++) {
            // check if i is a factor
            if(n % i == 0) {
                // check if the factor is prime
                if(isPrime(i)) {
                    result.push_back(i);
                }
                if(n/i != i) {
                    // check if the pair factor is prime
                    if(isPrime(n/i)) {
                        result.push_back(n/i);
                    }
                }
            }
        }
        return result;
    }

    // ***************************************
    // Prime Factorisation
    // 2 | 780
    // 2 | 390
    // 2 | 195
    // 3 | 65
    // 5 | 13
    // ------- terminates
    // 13 | 13
    //    | 1
    // Optimal Approach
    // T.C. : O(sqrt(N) * log(N)) ~ approximate
    // S.C. = O(1)
    vector<int> primeFactors_III(int n) {
        vector<int> result;
        // Because prime numbers start from 2
        for(int i = 2 ; i*i <= n ; i++) {
            // checking for a factor or divisor
            if(n % i == 0) {
                result.push_back(i);
                // keep dividing till it divides
                while(n % i == 0) {
                    n = n / i;
                }
            }
        }
        // if last number left is prime number 
        if(n != 1) result.push_back(n);
        return result;
    }
};

int main()
{
    return 0;
}