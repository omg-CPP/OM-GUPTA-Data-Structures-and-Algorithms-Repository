// Leetcode : 119 (EASY)

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
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long val = 1;
        int i = rowIndex;
        for(int j = 0 ; j <= rowIndex ; j++) {
            ans.push_back(val);
            val = val * (i-j)/(j+1);
        }
        return ans;
    }
};


int main()
{
    return 0;
}