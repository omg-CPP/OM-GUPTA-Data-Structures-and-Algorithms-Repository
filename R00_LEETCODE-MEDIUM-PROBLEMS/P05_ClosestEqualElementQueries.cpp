// Leetcode : 3488 (MEDIUM)

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

// T.C. = O(N) + O(Q*logN)
// S.C. = O(N)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;
        for(int& q : queries) {
            int element = nums[q];
            vector<int>& vec = mp[element];
            int size = vec.size();
            // no more occurence of this element
            if(size == 1) result.push_back(-1);
            else {
                // finding index 
                int pos = lower_bound(vec.begin(),vec.end(),q) - vec.begin();
                int res = INT_MAX;

                // right neighbour :: pos+1
                int right = vec[(pos+1) % size];
                int d_r = abs(q - right);
                int circular_d_r = n - d_r;
                res = min({res,d_r,circular_d_r});

                // left neighbour :: pos-1
                int left = vec[(pos-1+size) % size];
                int d_l = abs(q - left);
                int circular_d_l = n - d_l;
                res = min({res,d_l,circular_d_l});
                result.push_back(res);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}