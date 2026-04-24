// Segmented Sieve
// Constriants:
// 1 <= L <= R <= 1e12
// 0 <= R-L <= 1e6

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
int N = 1000000;
vector<bool> sieve(N+1,false);
// for R = 1e12, we need primes till 1e6 which is sqrt(1e12) to mark all primes...
// create a sieve of 1e6 space
void generateSieve() {
    for(int i = 2 ; i <= N ; i++) {
        sieve[i] = true;
    }

    for(int i = 2 ; i*i <= N ; i++) {
        if(sieve[i] == true) { // prime
            // mark all multiples as false
            for(int j = i*i ; j <= N ; j += i) {
                sieve[j] == false;
            }
        }
    }
}

vector<int> generatePrimes(int N) {
    vector<int> primes;
    for(int i = 2 ; i <= N ; i++) {
        if(sieve[i] == true) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    generateSieve();
    int t;
    cin>>t;
    while(t--) {
        ll L,R;
        cin>>L>>R;
        // step 1: generate all primes till sqrt(R)
        vector<int> primes = generatePrimes(sqrt(R));

        // step 2: create a dummy[] of size (R-L+1)
        vector<int> dummy(R-L+1,1);
        if(L == 1) dummy[0] = false;

        // step 3: mark all multiples of primes on dummy[] as false
        for(int& p : primes) {
            // trick to find first multiple for a L
            ll firstMultiple = (L / p) * p;
            if(firstMultiple < L) firstMultiple += p;
            for(ll i = max(firstMultiple, 1ll*p*p) ; i <= R ; i += p) {
                dummy[i-L] = false; // marking on dummy[]
            }
        }

        // step 4: get all the primes
        for(ll i = L ; i <= R ; i++) {
            if(dummy[i-L] == true) {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// 2
// 110 130
// 113 127 
// 1 100
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 