// Given a number n, determine whether it is a prime number or not.
// Note: A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.

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
    // T.C. = O(N)
    // S.C. = O(1)
    bool isPrime_Naive(int n) {
        bool flag = true; // means prime
        // 'i' is a factor of 'n'
        for(int i = 2 ; i <= n-1 ; i++) {
            if(n % i == 0) {
                flag = false; // means composite
                break;
            }
        }
        return flag;
    }

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

    // Optimal Approach
    // T.C. = O(sqrt(N))
    // S.C. = O(1)
    bool isPrime_Optimal(int n) {
        if(n <= 1) return false;
        int count = 0;
        for(int i = 1 ; i*i <= n ; i++) {
            if(n % i == 0) {
                count += 1;
                if(n/i != i) {
                    count += 1;
                }
            }
            // means number is composite
            if(count > 2) {
                return false;
            }
        }
        // count == 2
        return true; // means number is prime
    }
};

int main()
{
    Solution* objPtr = new Solution();
    // Prime Numbers : Number divisible by 1 and itself only
    // Prime Numbers : 2,3,5,7,11,13,17,19,---
    // 1 is Neither Prime Nor Composite
    // 2 is the only even prime number
    int n;
    cout<<"Enter the num : ";
    cin>>n;
    if(n <= 0) {
        cout<<"Invalid Choice!!"<<endl;
    }
    else if(n == 1) {
        cout<<"Neither Prime Nor Composite"<<endl;
    }
    else { // n > 1
        if(objPtr->isPrime_Optimal(n) == true) {
            cout<<"Prime Number"<<endl;
        }
        else { 
            cout<<"Composite Number"<<endl;
        }
    }
    return 0;
}