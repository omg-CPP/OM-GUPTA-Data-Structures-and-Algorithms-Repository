// Leetcode : 213

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(N)
// S.C. = O(1)
int rob_SpaceOptimised(vector<int>& nums) {
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1 ; i <= n-1 ; i++) {
        int pick = nums[i];
        if(i > 1) {
            pick += prev2;
        }
        int notPick = 0 + prev1;
        int curi = max(pick,notPick);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    vector<int> temp1, temp2;
    for(int i = 0 ; i < n ; i++) {
        if(i != 0) {
            temp1.push_back(nums[i]);
        }
        if(i != n-1) {
            temp2.push_back(nums[i]);
        }
    }
    int ans1 = rob_SpaceOptimised(temp1);
    int ans2 = rob_SpaceOptimised(temp2);
    return max(ans1,ans2);
}

int main()
{
    return 0;
}