// Leetcode : 3761 (MEDIUM)

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
    // T.C. = O(N)
    // S.C. = O(N)
    // function to reverse number 
    int reverseNum(int num) {
        int rev = 0;
        while(num > 0) {
            rev = (rev*10) + (num%10);
            num /= 10;
        }
        return rev;
    }
    // actual function 
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp; // {value->latestIdx}
        int ans = INT_MAX;

        for(int i = 0 ; i < n ; i++) {
            // check if current number exists as key
            if(mp.count(nums[i])) {
                ans = min(ans,i - mp[nums[i]]);
            }
            // store reverse of current number
            int rev = reverseNum(nums[i]);
            mp[rev] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main()
{
    return 0;
}