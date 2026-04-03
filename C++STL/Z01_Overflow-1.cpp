
// see how factorial of a number, behaves differently for different datatypes...

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

typedef long long int ll;
typedef unsigned long long int ull;
// MOD is prime
const int MOD = 1e9+7;

// normal function
int factorial(int n) {
    int fact = 1;
    for(int i = 1 ; i <= n ; i++) {
        fact = fact * i;
    }
    return fact;
}

// way 1: to use long long 
ll factorialOfBigNumber(int n) {
    ll fact = 1;
    for(int i = 1 ; i <= n ; i++) {
        fact = fact * i;
    }
    return fact;
}
// int ->  32-bit signed integer
// Range: [-2^31, 2^31-1]
// -2147483648  to  2147483647 (> 1e9)

// long long ->  64-bit signed integer
// Range: [-2^63, 2^63-1]
// -9223372036854775808  to  9223372036854775807 (< 21!)
// Max value of long long (signed 64-bit) :: 2^63 − 1 = 9223372036854775807 = ~(20!)
// 20! < 2^63 − 1 < 21!

// way 2: to use modulo airthmetic
// MOD = p = 1e9+7
// n = Max value of int = 2,147,483,647
// for n >= MOD => n >= p
// (n!) % p = 0
// n! = 1×2×3×⋯×(p−1)×p×(p+1)…n
// (something×p) mod p = 0
ll factorialOfBigNumberUsingModulo(int n) {
    if(n >= MOD) {
        return 0;
    }
    ll fact = 1;
    for(int i = 1 ; i <= n ; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}


// 🔥 CP Rule to Remember:

// You almost never compute factorial directly beyond 10^7, 
// for(int i = 1; i <= n; i++)
// 👉 Time complexity = O(n)
// Typical CP constraints:
// ~ 10^8 operations/sec (optimistic in C++)
// Time limit: 1–2 seconds

// B. We never store exact factorial beyond 20!, as long long limit is < 21!


int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<factorial(n)<<endl;
    cout<<factorialOfBigNumber(n)<<endl;
    cout<<factorialOfBigNumberUsingModulo(n)<<endl;


    int a = 1e9, b = 1e9;

    // WRONG
    long long res = a * b;   // overflow before assignment
    cout<<res<<endl; // -1486618624

    // CORRECT
    long long ans = 1LL * a * b;
    cout<<ans<<endl; // 1000000000000000000 (1e18) < 2^63 − 1 ≈ 9.22×10^18 ~~ (9e18)
    return 0;
}

// Enter n: 12
// 479001600
// 479001600
// 479001600


// Enter n: 20
// -2102132736 ❌ Overflow
// 2432902008176640000
// 146326063


// Enter n: 234156215
// 0 ❌ Overflow
// 0 ❌ Overflow
// 676644228