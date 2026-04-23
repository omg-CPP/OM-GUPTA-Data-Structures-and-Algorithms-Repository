// Print the count of all primes in range L to R
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
    // Brute force
    bool isPrime(int n) {
        if(n <= 1) return false;
        int count = 0;
        for(int i = 1 ; i*i <= n ; i++) {
            if(n % i == 0) {
                count += 1;
                if(n/i != i) {
                    count += 1;
                }
            }
            if(count > 2) return false; // means composite
        }
        // count == 2
        return true; // means prime
    }

    // T.C. = O(Q * (R-L+1) * (sqrt(N)))
    // S.C. = O(1)
    vector<int> countPrimes_I(vector<pair<int,int>> queries) {
        int n = queries.size();
        vector<int> ans;
        for(auto& query : queries) {
            int L = query.first;
            int R = query.second;
            int count = 0;
            for(int i = L ; i <= R ; i++) {
                if(isPrime(i)) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }


    // **********************************************************************


    // Better Solution : using Sieve
    // pre-computation of the black-box
    vector<int> generateSieve(int n) {
        vector<int> isPrime(n+1,1);
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2 ; i*i <= n ; i++) {
            if(isPrime[i] == 1) {
                // marking all multiples of i as composite (0)
                for(int j = i*i ; j <= n ; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return isPrime;
    }

    // Constraints:
    // Q <= 1e5
    // 1 <= L <= R <= 1e6
    // T.C. = O(Q * (R-L+1))
    // S.C. = O(1e6)
    vector<int> countPrimes_II(vector<pair<int,int>> queries) {
        int n = queries.size();
        vector<int> isPrime = generateSieve(1e6);
        vector<int> ans;
        for(auto& query : queries) {
            int L = query.first;
            int R = query.second;
            int count = 0;
            for(int i = L ; i <= R ; i++) {
                // prime (1)
                if(isPrime[i] == 1) { // O(1)
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }


    // **********************************************************************


    // Most Optimal Solution
    //        sieve               queries prefixSum[]
    // T.C. = O(1e6*log(log(1e6))) + O(Q) + O(1e6)
    // S.C. = O(1e6)
    vector<int> countPrimes_III(vector<pair<int,int>> queries) {
        int n = queries.size();
        vector<int> isPrime = generateSieve(1e6);
        // converting isPrime[] into a prefixSum[]
        for(int i = 2 ; i <= 1e6 ; i++) {
            isPrime[i] = isPrime[i] + isPrime[i-1];
        }
        vector<int> ans;
        for(auto& query : queries) {
            int L = query.first;
            int R = query.second;
            int count = 0;
            // 1 <= L
            count += isPrime[R] - isPrime[L-1];
            ans.push_back(count);
        }
        return ans;
    }

};

int main()
{
    return 0;
}