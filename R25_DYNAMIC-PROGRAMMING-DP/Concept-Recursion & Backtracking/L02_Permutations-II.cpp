// Leetcode : 47

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time: O(N*N!) 
//       freq[] rec stack space
// Space: O(N) + O(N)
void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, vector<int>& frequency) {
    int n = nums.size();
    // base case
    if(v.size() == n) {
        ans.push_back(v);
        return;
    }
    for(int i = 0 ; i < n ; i++) {
        // skip if already used
        if(frequency[i] == 1) {
            continue;
        }
        // skip duplicates if the previous same number is not found 
        // along the same current path, which means that this previous
        // number is already started a new path before, so we will not 
        // pick the current same number, to avoid duplicacy.
        if(i > 0 && nums[i] == nums[i-1] && frequency[i-1] == 0) {
            continue;
        }
        v.push_back(nums[i]);
        frequency[i] = 1;
        helper(nums,v,ans,frequency);
        // backtracking
        frequency[i] = 0;
        v.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    // IMPORTANT: sort first
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> v;
    vector<int> frequency(n,0);
    helper(nums,v,ans,frequency);
    return ans;
}

int main()
{
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = permuteUnique(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        for(int j = 0 ; j < ans[i].size() ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1 1 2 
// 1 2 1 
// 2 1 1 