// Leetcode : 2553 (EASY)

// Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

// To separate the digits of an integer is to get all the digits it has in the same order.

// For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

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
    // Let N be the length of nums, and let M be the maximum value in nums.
    // Approach I: Forward Traversal
    // T.C. = O(N*logM)
    // S.C. = O(logM) :: temp[]
    vector<int> separateDigits_F(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int i = 0;
        while(i < n) {
            int num = nums[i];
            vector<int> temp;
            while(num != 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            for(int j = temp.size()-1 ; j >= 0 ; j--) {
                ans.push_back(temp[j]);
            }
            i++;
        }
        return ans;
    }

    // Approach II: Reversal Traversal
    // T.C. = O(N*logM)
    // S.C. = O(1)
    vector<int> separateDigits_R(vector<int>& nums) {
        vector<int> res;
        for(int i = nums.size()-1 ; i >= 0 ; i--) {
            int x = nums[i];
            while(x != 0) {
                res.push_back(x % 10);
                x /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}