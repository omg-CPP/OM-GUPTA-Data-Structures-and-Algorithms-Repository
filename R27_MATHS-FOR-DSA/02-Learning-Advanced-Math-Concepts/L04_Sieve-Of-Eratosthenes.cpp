// Sieve of Eratosthenes
// Given a number N, count all primes till N.

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

// Brute Force
// T.C. = O(N * sqrt(N))
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

int countPrimesTillN(int n) {
    vector<int> res;
    for(int i = 2 ; i <= n ; i++) {
        if(isPrime(i)) {
            res.push_back(i);
        }
    }
    for(int& p : res) cout<<p<<" ";
}


// **********************************************

// Structure Code: slight optimised
int fun(int n) {
    int count = 0;
    if(n < 2) {
        return 0;
    }
    // pre-computation
    vector<int> isPrime(n+1,1);
    // base cases
    isPrime[0] = 0;
    isPrime[1] = 0;

    for(int i = 2 ; i <= n ; i++) {
        if(isPrime[i] == 1) {
            for(int j = 2*i ; j <= n ; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for(int i = 2 ; i <= n ; i++) {
        if(isPrime[i] == 1) {
            count++;
        }
    }
    return count;
}

// ********************************************************

// Count Primes Till N
// Most Optimal Solution using Sieve of Eratosthenes
// T.C. = O(N) + O(N*log(logN)) + O(N)
// S.C. = O(N)
// prime harmonic series
int countPrimes(int n) {
    // n < 2 -> 0,1
    if(n < 2) {
        return 0;
    }
    // pre-computation
    vector<int> isPrime(n+1,1);
    // base cases
    isPrime[0] = 0;
    isPrime[1] = 0;

    // start from number 2 to N
    for(int i = 2 ; i*i <= n ; i++) {
        // prime then multiples of it will be composite
        if(isPrime[i] == 1) {
            // marking all multiples of i as 0
            for(int j = i*i ; j <= n ; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    int count = 0;
    // return the number of prime numbers that are strictly less than n
    for(int i = 2 ; i <= n ; i++) {
        if(isPrime[i] == 1) {
            count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}