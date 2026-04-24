// Smallest Prime Factor :: GFG

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
    // eg. n = 60
    // {2,2,3,5}
    vector<int> getPrimeFactorisation(int n) {
        vector<int> ans;
        for(int i = 2 ; i*i <= n ; i++) {
            if(n % i == 0) {
                while(n % i == 0) {
                    ans.push_back(i);
                    n /= i;
                }
            }
        }
        if(n != 1) ans.push_back(n);
        return ans;
    }

    // T.C. = O(Q * sqrt(N)) :: worst case for prime number like = 17
    // S.C. = O(1)
    vector<vector<int>> leastPrimeFactor_I(vector<int> queries) {
        vector<vector<int>> result;
        for(int& query : queries) {
            int N = query;
            result.push_back(getPrimeFactorisation(N));
        }
        return result;
    }



    // *********************************************************


    // Constriants: 2 <= n <= 1e5
    // Optimal Method: N = 1e5
    // T.C. = O(N*log(logN)) + O(Q) 
    // S.C. = O(N)

    vector<int> generateSieve(int n) {
        vector<int> leastPrime(n+1,0);
        for(int i = 0 ; i <= n ; i++) {
            leastPrime[i] = i;
        }
        for(int i = 2 ; i*i <= n ; i++) {
            if(leastPrime[i] == i) {
                // marking all multiples of i with i, which is least prime factor
                for(int j = i*i ; j <= n ; j += i) {
                    // if position is un-marked till now, do not over-ride
                    if(leastPrime[j] == j) {
                        leastPrime[j] = i;
                    }
                }
            }
        }
        return leastPrime;
    }

    vector<int> leastPrimeFactor_II(vector<int> queries) {
        vector<int> leastPrime = generateSieve(1e5);
        vector<int> result;
        for(int& query : queries) {
            int N = query;
            result.push_back(leastPrime[N]);
        }
        return result;
    }

    // ***********************************************
    
    // Optimal Way to print all prime factors with repetition
    // for eg. if number is 60 -> 2,2,3,5
    vector<int> factorisePrime(int n) {
        vector<int> leastPrime = generateSieve(n);
        vector<int> ans;
        while(n != 1) {
            ans.push_back(leastPrime[n]);
            n /= leastPrime[n];
        }
        return ans;
    }
};

int main()
{
    Solution* objPtr = new Solution();
    vector<int> queries = {3,12,16,60};
    vector<vector<int>> result = objPtr->leastPrimeFactor_I(queries);
    for(int i = 0 ; i < result.size() ; i++) {
        for(int j = 0 ; j < result[i].size() ; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    // 3 
    // 2 2 3 
    // 2 2 2 2 
    // 2 2 3 5 

    vector<int> ans = objPtr->leastPrimeFactor_II(queries);
    for(int& val : ans) cout<<val<<" ";
    // 3 2 2 2 
    cout<<endl<<endl;

    vector<int> res = objPtr->factorisePrime(60);
    for(int& val : res) cout<<val<<" ";
    // 2 2 3 5 
    cout<<endl;
    return 0;
}


