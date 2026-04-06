// GFG

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
    // this is a code where maxi, sec_maxi and third_maxi could be same,
    // because we have not put any condition on them...
    vector<int> thirdLargestI(vector<int>& nums) {
        // code here
        int n = nums.size();
        int maxi = INT_MIN;
        int sec_maxi = INT_MIN;
        int third_maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] > maxi) {
                third_maxi = sec_maxi;
                sec_maxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > sec_maxi) {
                third_maxi = sec_maxi;
                sec_maxi = nums[i];
            }
            else if(nums[i] > third_maxi) {
                third_maxi = nums[i];
            }
        }
        return {maxi,sec_maxi,third_maxi};
    }

    // in this code, maxi, sec_maxi and third_maxi, any of one could not be,
    // identical with any other two...
    vector<int> thirdLargestII(vector<int>& nums) {
        // code here
        int n = nums.size();
        int maxi = INT_MIN;
        int sec_maxi = INT_MIN;
        int third_maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            // nums = {6,6,5}
            if(nums[i] > maxi) {
                third_maxi = sec_maxi;
                sec_maxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > sec_maxi && nums[i] != maxi) {
                third_maxi = sec_maxi;
                sec_maxi = nums[i];
            }
            else if(nums[i] > third_maxi && nums[i] != maxi && nums[i] != sec_maxi) {
                third_maxi = nums[i];
            }
        }
        return {maxi,sec_maxi,third_maxi};
    }
};

int main()
{
    vector<int> nums = {7,7,7};
    Solution* obj = new Solution();
    vector<int> ans = obj->thirdLargestI(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<((ans[i] == INT_MIN) ? -1 : ans[i])<<" ";
    }
    cout<<endl;

    vector<int> res = obj->thirdLargestII(nums);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<((res[i] == INT_MIN) ? -1 : res[i])<<" ";
    }
    cout<<endl;
    return 0;
}

// test cases
// {5,4,6,6,6} -> {6 6 6} & {6 5 4}
// {5,4,6,4,3} -> {6 5 4} & {6 5 4}
// {5,5,3,2,6} -> {6 5 5} & {6 5 3}
// {5,5,6} -> {6 5 5} & {6 5 -1}
// {7,7,7} -> {7 7 7} & {7 -1 -1}
// {6,5} -> {6 5 -1} & {6 5 -1}
// {7,7} -> {7 7 -1} & {7 -1 -1}
// {10} -> {10 -1 -1} & {10 -1 -1} 
// {0,0,0} -> {0 0 0} & {0 -1 -1}
// {0,0} -> {0 0 -1} & {0 -1 -1}
// {0} -> {0 -1 -1} & {0 -1 -1}