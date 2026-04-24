// Concept to calculate (nCr) % M
// or (a/b) % M = (a * ((b^M-2) % M)) % M
// nCr = (a*b^M−2) % M

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

int M = 1e9+7;
typedef long long ll;

// O(N)
int factorial(int num) {
    int fact = 1;
    for(int i = 1 ; i <= num ; i++) {
        fact = (1LL * fact * i) % M;
    }
    return fact;
}

// Binary Exponentiation
// T.C. = O(logN)
// S.C. = O(logN)
int findPower_Recursive(int x, int N) {
    // base case
    if(N == 0) return 1;
    // writing recurrences
    int half = findPower_Recursive(x,N/2);
    int result = (1LL * half * half) % M;
    if(N & 1) { // power (N) -> odd 
        result = (1LL * result * x) % M;
    }
    return result;
}

int modular_nCr(int n, int r) {
    // base cases
    if(r < 0 || r > n) {
        return 0;
    }
    int a = factorial(n);
    int b = (1LL * factorial(r) * factorial(n-r)) % M;
    return (1LL * a * findPower_Recursive(b,M-2)) % M;
}

int main()
{
    return 0;
}