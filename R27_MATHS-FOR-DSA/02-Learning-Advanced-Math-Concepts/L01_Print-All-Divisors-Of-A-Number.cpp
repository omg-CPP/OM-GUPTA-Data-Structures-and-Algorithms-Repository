// Printing all Divisors / Factors of a Number
// Given an integer n, print all the divisors of N in the ascending order.

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

// Brute Force Approach: 
// T.C. = O(N)
// S.C. = O(1)
void print_divisors_Naive(int n) {
    // iterating over all divisors / factors of n
    for(int i = 1 ; i <= n ; i++) {
        if(n % i == 0) {
            cout<<i<<" ";
        }
    }
    return;
}


// ******************** 

// refer to this:
// 36 : 1 2 3 4 6 9 12 18 36 

// 1 * 36 = 36
// 2 * 18 = 36
// 3 * 12 = 36
// 4 * 9 = 36
// 6 * 6 = 36
// --------------
// 9 * 4 = 36
// 12 * 3 = 36
// 18 * 2 = 36
// 36 * 1 = 36


// Optimal Approach:
// T.C. = O(sqrt(N))
// S.C. = O(1)
void print_divisors_Optimal(int n) {
    // iterating over all divisors / factors of n
    vector<int> factors;
    // instead of i <= sqrt(n) write i*i <= n
    for(int i = 1 ; i*i <= n ; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            // condition to restrict duplicates in case of perfect square number
            if(n / i != i) {
                factors.push_back(n/i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    for(int& factor : factors) {
        cout<<factor<<" ";
    }
    return;
}


int main()
{
    int n = 60;
    print_divisors_Naive(n); // 1 2 3 4 6 9 12 18 36 
    cout<<endl;
    print_divisors_Optimal(n); // 1 2 3 4 6 9 12 18 36 
    return 0;
}