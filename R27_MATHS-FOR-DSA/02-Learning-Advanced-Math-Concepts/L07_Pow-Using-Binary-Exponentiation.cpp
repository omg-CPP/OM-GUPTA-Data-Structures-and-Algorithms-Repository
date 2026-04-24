// Leetcode : 50 (MEDIUM)

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

typedef long long ll;

// Approach 1: using brute force logic
// T.C. = O(N)
// S.C. = O(1)
double myPow_NaiveApproach(double x, int n) {
    // Corner Cases : Constant Operations
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && !(n & 1)) return 1.0;
    if(x == -1 && (n & 1)) return -1.0;

    ll N = n;
    double power = 1.0;
    if(N < 0) {
        x = 1/x;
        N = -N;
    }
    for(ll i = 1 ; i <= N ; i++) {
        power *= x;
    }
    return power;
}



// ******************************************




// Approach 2: using Binary or Fast Exponentiation (Iterative)
// T.C. = O(logN)
// S.C. = O(1)
double myPow_Iterative_BinExp(double x, int n) {
    // Corner Cases : Constant Operations
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && !(n & 1)) return 1.0;
    if(x == -1 && (n & 1)) return -1.0;

    // -2^31 <= n <= 2^31-1
    // Binary Exponentiation
    ll N = n;
    double power = 1.0;
    // To handle -ve value of n
    if(N < 0) {
        x = 1/x;
        N = -N;
    }
    // we are actually traversing on the binary form of n
    // binary number digits -> log2(N) + 1
    while(N > 0) {
        if(N & 1) { // last (least significant bit) bit of N = 1
            power = power * x;
        }
        x *= x;
        N = N >> 1; // dividing the number by 2 -> rightshift operator
    }
    return power;
}



// ******************************************



// Approach 3: using Binary or Fast Exponentiation (Recursive)
// T.C. = O(logN)
//       recursive depth
// S.C. = O(logN)
double findPower_Recursive(double x, ll N) {
    // base case
    if(N == 0) return 1.0;
    // writing recurrences
    double half = findPower_Recursive(x,N/2);
    double result = half * half;
    if(N & 1) { // power (N) -> odd 
        result = result * x;
    }
    return result;
}

double myPow(double x, int n) {
    // Corner Cases : Constant Operations
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && !(n & 1)) return 1.0;
    if(x == -1 && (n & 1)) return -1.0;

    // -2^31 <= n <= 2^31-1
    // Binary Exponentiation
    ll N = n;
    // To handle -ve value of n
    if(N < 0) {
        x = 1/x;
        N = -N;
    }
    return findPower_Recursive(x,N);
}



int main()
{
    return 0;
}