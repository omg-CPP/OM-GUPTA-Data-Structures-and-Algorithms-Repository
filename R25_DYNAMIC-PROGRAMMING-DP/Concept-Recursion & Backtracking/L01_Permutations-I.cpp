// Leetcode : 46

#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, vector<int>& frequency) {
    int n = nums.size();
    // base case
    if(v.size() == n) {
        ans.push_back(v);
        return;
    }
    for(int i = 0 ; i < n ; i++) {
        // if they previously taken than don't add them in v
        if(!frequency[i]) { 
            v.push_back(nums[i]);
            frequency[i] = 1;
            helper(nums,v,ans,frequency);
            // backtracking happens at this step
            frequency[i] = 0;
            v.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> v;
    vector<int> frequency(n,0);
    helper(nums,v,ans,frequency);
    return ans;
}


int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        for(int j = 0 ; j < ans[i].size() ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 