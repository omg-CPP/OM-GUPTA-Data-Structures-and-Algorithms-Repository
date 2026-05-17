// DAT

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

// sum update difference array
void differenceArrayUpdate(vector<int>& nums, vector<int>& query) {
    int n = nums.size();
    int L = query[0];
    int R = query[1];
    int val = query[2]; // val to update
    vector<int> diffArray(n,0);
    diffArray[L] = val;
    if(R+1 < n) {
        diffArray[R+1] = -val;
    }
    // idea of cumulative sum
    // difffArray[] = {0,0,0,0,0,0,0,0,0}
    //              = {0,2,0,0,0,0,0,-2,0}
    //              = {0,2,2,2,2,2,2,0,0}
    for(int i = 0 ; i < n ; i++) {
        if(i-1 >= 0) {
            diffArray[i] = diffArray[i] + diffArray[i-1];
        }
    }
    // now adding the changes
    for(int i = 0 ; i < n ; i++) {
        nums[i] = nums[i] + diffArray[i];
    }
}


// multiply update difference array
void differenceArrayUpdate_Multiply(vector<int>& nums, vector<int>& query) {
    int n = nums.size();
    int L = query[0];
    int R = query[1];
    int val = query[2]; // val to update
    vector<double> diffArray(n,1);
    diffArray[L] *= val;
    if(R+1 < n) {
        diffArray[R+1] /= val;
    }
    // idea of cumulative sum
    // difffArray[] = {1,1,1,1,1,1,1,1,1}
    //              = {1,2,1,1,1,1,1,-2,1}
    //              = {1,2,2,2,2,2,2,1,1}
    for(int i = 0 ; i < n ; i++) {
        if(i-1 >= 0) {
            diffArray[i] = diffArray[i] * diffArray[i-1];
        }
    }
    // now adding the changes
    for(int i = 0 ; i < n ; i++) {
        nums[i] = nums[i] * diffArray[i];
    }
}

int main()
{
    vector<int> nums = {2,3,1,5,4,2,1,3,6};
    vector<int> query1 = {1,6,2};
    differenceArrayUpdate(nums,query1);
    for(auto& num : nums) cout<<num<<" ";
    // 2 5 3 7 6 4 3 3 6 
    cout<<endl;

    vector<int> arr = {2,3,1,5,4,2,1,3,6};
    vector<int> query2 = {1,6,2};
    differenceArrayUpdate_Multiply(arr,query2);
    for(auto& num : arr) cout<<num<<" ";
    // 2 6 2 10 8 4 2 3 6
    cout<<endl;

    return 0;
}