// Binary to Decimal Conversion

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

// binary[i] == '1', to convert it in number 1, ('1'-'0')
// otherwise it will perform calculation for ASCII values
// T.C. = O(len)
// S.C. = O(1)
int binaryToDecimal(string binary) {
    int len = binary.length();
    int powOf2 = 1; // 2^0
    int num = 0;
    for(int i = len-1 ; i >= 0 ; i--) {
        if(binary[i] == '1') {
            num += ((binary[i] - '0') * powOf2);
        }
        // No need to add if binary[i] == '0'
        powOf2 = powOf2 * 2;
    }
    return num;
}

int main()
{
    string binary = "1101";
    string s = "111";
    cout<<binaryToDecimal(binary)<<endl; // 13
    cout<<binaryToDecimal(s)<<endl; // 7
    cout<<binaryToDecimal("10010")<<endl; // 18
    cout<<binaryToDecimal("1000")<<endl; // 8
    return 0;
}