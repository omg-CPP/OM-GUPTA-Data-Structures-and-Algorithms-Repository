
#include <iostream>
#include <vector>
using namespace std;

// print all the subsequences
void printAllSubsequences(int sum, vector<int>& v, int idx, int k, vector<int>& nums) {
    int n = nums.size();
    if(idx == n) {
        if(sum == k) {
            for(int i = 0 ; i < v.size() ; i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    v.push_back(nums[idx]);
    sum += nums[idx];
    // pick call
    printAllSubsequences(sum,v,idx+1,k,nums);
    // when returning back to previous call removing all added
    sum -= nums[idx];
    v.pop_back();
    // not pick call
    printAllSubsequences(sum,v,idx+1,k,nums);
}

// print any one subsequence of all the others
bool printOneSubsequence(int sum, vector<int>& v, int idx, int k, vector<int>& nums) {
    int n = nums.size();
    if(idx == n) {
        // condition satisfied
        if(sum == k) {
            for(int i = 0 ; i < v.size() ; i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            return true;
        }
        // condition not satisfied
        else {
            return false;
        }
    }
    v.push_back(nums[idx]);
    sum += nums[idx];
    // pick call
    if(printOneSubsequence(sum,v,idx+1,k,nums) == true) {
        return true;
    }
    // when returning back to previous call removing all added
    sum -= nums[idx];
    v.pop_back();
    // not pick call
    if(printOneSubsequence(sum,v,idx+1,k,nums) == true) {
        return true;
    }
    return false;
}

// count all subsequences with sum = k
int countAllSubsequences(int sum, int idx, int k, vector<int>& nums) {
    int n = nums.size();
    // condition not satisfied
    if(sum > k) {
        return 0;
    }
    if(idx == n) {
        // condition satisfied
        if(sum == k) {
            return 1;
        }
        // condition not satisfied
        else {
            return 0;
        }
    }
    sum += nums[idx];
    // pick call
    int left = countAllSubsequences(sum,idx+1,k,nums);
    // when returning back to previous call removing all added
    sum -= nums[idx];
    // not pick call
    int right = countAllSubsequences(sum,idx+1,k,nums);
    return left + right;
}

int main()
{
    vector<int> nums = {1,2,1};
    int k = 2;
    vector<int> v;
    //                 sum,v,idx
    printAllSubsequences(0,v,0,k,nums);
    // 1 1 
    // 2 
    printOneSubsequence(0,v,0,k,nums);
    // 1 1 
    cout<<countAllSubsequences(0,0,k,nums); // 2
    return 0;
}

// 1 1 
// 2 