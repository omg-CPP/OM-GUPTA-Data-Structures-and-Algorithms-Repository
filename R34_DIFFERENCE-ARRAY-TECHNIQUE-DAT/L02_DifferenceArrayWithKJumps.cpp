// DAT with Jumps

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

// case 1: updation is about summation of a value
void differenceArrayWithJumps(vector<int>& nums, vector<int>& query) {
    int n = nums.size();
    int L = query[0];
    int R = query[1];
    int val = query[2]; // val to update
    int k = query[3]; // jump
    vector<int> diffArray(n,0);
    diffArray[L] = val;
    int steps = (R-L)/k;
    int next = L + ((steps+1)*k);
    if(next < n) {
        diffArray[next] = -val;
    }
    // idea of cumulative sum
    // query = {1,6,2,2}
    // difffArray[] = {0,0,0,0,0,0,0,0,0,0,0,0}
    //              = {0,2,0,0,0,0,0,-2,0,0,0,0}
    //              = {0,2,0,2,0,2,0,0,0,0,0,0}
    for(int i = 0 ; i < n ; i++) {
        if(i-k >= 0) {
            diffArray[i] = diffArray[i] + diffArray[i-k];
        }
    }
    // now adding the changes
    for(int i = 0 ; i < n ; i++) {
        nums[i] = nums[i] + diffArray[i];
    }

    // printing difference array
    for(int& diff : diffArray) cout<<diff<<" ";
    // 0 2 0 2 0 2 0 0 0 0 0 0 
    cout<<endl;
}


// case 2: updation is about multiplication of a value
// can be optimised for large values by using modulo airthetic
void differenceArrayWithJumps_Multiply(vector<int>& nums, vector<int>& query) {
    int n = nums.size();
    int L = query[0];
    int R = query[1];
    int val = query[2]; // val to update
    int k = query[3]; // jump
    vector<double> diffArray(n,1);
    diffArray[L] *= val;
    int steps = (R-L)/k;
    int next = L + ((steps+1)*k);
    if(next < n) {
        diffArray[next] /= val;
    }
    // idea of cumulative sum
    // query = {1,8,4,3}
    // difffArray[] = {1 1 1 1 1 1 1 1 1 1 1 1 1}
    //              = {1 4 1 1 4 1 1 4 1 1 1 1 1}
    //              = {1 8 3 4 20 6 7 32 9 1 2 3 4}
    for(int i = 0 ; i < n ; i++) {
        if(i-k >= 0) {
            diffArray[i] = diffArray[i] * diffArray[i-k];
        }
    }
    // now adding the changes
    for(int i = 0 ; i < n ; i++) {
        nums[i] = nums[i] * diffArray[i];
    }

    // printing difference array
    for(double& diff : diffArray) cout<<diff<<" ";
    // 1 4 1 1 4 1 1 4 1 1 1 1 1
    cout<<endl;
}

int main()
{
    vector<int> nums = {1,2,3,2,2,1,2,4,2,5,2,1};
    vector<int> query1 = {1,6,2,2};
    differenceArrayWithJumps(nums,query1);
    for(auto& num : nums) cout<<num<<" ";
    // 1 4 3 4 2 3 2 4 2 5 2 1 
    cout<<endl;

    vector<int> arr = {1,2,3,4,5,6,7,8,9,1,2,3,4};
    vector<int> query2 = {1,8,4,3};
    differenceArrayWithJumps_Multiply(arr,query2);
    for(auto& num : arr) cout<<num<<" ";
    // 1 8 3 4 20 6 7 32 9 1 2 3 4
    cout<<endl;
    return 0;
}