// Decimal to Binary Conversion

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

//        n->n/2->n/4->n/8->------->1 
// T.C. = O(log2(n))
//        string res length = no of remainders we fetched
// S.C. = O(log2(n))
string decimalToBinary(int n) {
    string res = "";
    while(n != 1) {
        if(n % 2 == 1) {
            res += '1';
        }
        else { // n % 2 == 0
            res += '0';
        }
        n = n / 2;
    }
    // adding last left '1' to the string
    res += '1';
    reverse(res.begin(),res.end());
    return res;
}

int main()
{   
    cout<<decimalToBinary(7)<<endl; // 111
    cout<<decimalToBinary(13)<<endl; // 1101
    cout<<decimalToBinary(8)<<endl; // 1000
    cout<<decimalToBinary(18)<<endl; // 10010
    return 0;
}