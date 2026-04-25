// Leetcode : 118 (EASY)

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
    // Tabulation DP
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // generating pascal triangle
        for(int i = 0 ; i < numRows ; i++) {
            vector<int> v(i+1,0);
            ans.push_back(v);
            for(int j = 0 ; j <= i ; j++) {
                if(j == 0 || i == j) {
                    ans[i][j] = 1;
                }
                else {
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}