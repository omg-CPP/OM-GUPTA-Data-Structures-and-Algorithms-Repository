// GFG

// Strong Numbers are the numbers whose sum of factorial of digits is equal to the original number. Given a number N, the task is to check if it is a Strong Number or not. Print 1 if the Number is Strong, else Print 0.

// Example 1:

// Input:
// N = 145
// Output:
// 1
// Explanation:
// 1! + 4! + 5! = 145 So, 145 is a Strong
// Number and therefore the Output 1.

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
    int factorial(int n) {
        int fact = 1;
        for(int i = 1 ; i <= n ; i++) {
            fact = fact * i;
        }
        return fact;
    }
    
    int isStrong(int N) {
        // code here
        int temp = N;
        int sum = 0;
        while(temp > 0) {
            sum = sum + factorial(temp % 10);
            temp /= 10;
        }
        if(sum == N) return 1;
        else return 0;
    }
};


int main()
{
    return 0;
}