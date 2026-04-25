// Leetcode : 2221 (MEDIUM)

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
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++) {
            for(int j = 0 ; j < n-1-i ; j++) {
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
        }
        return nums[0];
    }
}; 
 
//  1  2  3  4  5  : arr
//   3  5  7  9    : 1
//    8  2  6      : 2
//     0  8        : 3 
//      8          : 4

int main()
{
    return 0;
}