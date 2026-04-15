// GFG

// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].


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
    // T.C. = O(1)
    // S.C. = O(1)
    int findXOR_1ToN(int n) {
        if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n+1;
        else if(n % 4 == 3) return 0;
        else if(n % 4 == 0) return n;
    }

    // Brute Force:
    // T.C. = O(r-l+1)
    // S.C. = O(1)
    int findXOR_NaiveSoln(int l, int r) {
        // complete the function here
        int xorr = 0;
        for(int i = l ; i <= r ; i++) {
            xorr = xorr ^ i;
        }
        return xorr;
    }

    // optimal way
    // T.C. = O(1)
    // S.C. = O(1)
    int findXOR(int l, int r) {
        // complete the function here
        if(l == 1) return findXOR_1ToN(r);
        int xor1 = findXOR_1ToN(l-1);
        int xor2 = findXOR_1ToN(r);
        return xor1 ^ xor2;
    }
};

int main()
{
    return 0;
}