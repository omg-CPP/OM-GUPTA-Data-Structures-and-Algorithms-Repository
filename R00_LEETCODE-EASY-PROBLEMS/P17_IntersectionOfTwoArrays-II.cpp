// Leetcode : 350 (EASY)

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

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
    // T.C. = O(N*logN) + O(M*logM) + O(M+N)
    // S.C. = O(1)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // O(N*logN) 
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> intersection;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                intersection.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else { // nums1[i] > nums2[j]
                j++;
            }
        }
        return intersection;
    }


    // optimal soln: using map, when order does not matter
    // T.C. = O(M+N)
    // S.C. = O(N)
    vector<int> intersect_(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> result;

        for(int num : nums1) {
            freq[num]++;
        }

        for(int num : nums2) {
            if(freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}