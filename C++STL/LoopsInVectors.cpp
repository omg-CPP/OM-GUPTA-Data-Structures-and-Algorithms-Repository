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
int main()
{
    vector<int> nums = {1,2,3,4,5};
    int n = nums.size();

    // ****************

    // for loop :: most common
    for(int i = 0 ; i < n ; i++) {
        cout<<nums[i]<<" ";
    }
    // 1 2 3 4 5 
    cout<<endl;


    // while loop
    int i = 0;
    while(i < n) {
        cout<<nums[i]<<" ";
        i++;
    }
    // 1 2 3 4 5 
    cout<<endl;

    // do-while loop
    i = 0;
    do {
        cout<<nums[i]<<" ";
        i++;
    }
    while(i < n);
    // 1 2 3 4 5 
    cout<<endl;

    // ****************

    // for-each loop
    for(int& it : nums) {
        cout<<it<<" ";
    }
    // 1 2 3 4 5 
    cout<<endl;

    // using auto in for-each loop :: commonly used in CP
    for(auto& it : nums) {
        cout<<it<<" ";
    }
    // 1 2 3 4 5 
    cout<<endl;

    // ****************

    // using itertor
    for(vector<int>::iterator it = nums.begin() ; it != nums.end() ; it++) {
        cout<<*(it)<<" ";
    }
    // 1 2 3 4 5 
    cout<<endl;

    // using auto in itertor
    for(auto it = nums.begin() ; it != nums.end() ; it++) {
        cout<<*(it)<<" ";
    }
    // 1 2 3 4 5 
    cout<<endl;

    // ****************

    // printing reverse array
    for(int i = n-1 ; i >= 0 ; i--) {
        cout<<nums[i]<<" ";
    }
    // 5 4 3 2 1 
    cout<<endl;

    // using reverse-iterator
    for(vector<int>::reverse_iterator itr = nums.rbegin() ; itr != nums.rend() ; itr++) {
        cout<<*(itr)<<" ";
    }
    // 5 4 3 2 1 
    cout<<endl;

    // using auto in reverse-itertor
    for(auto itr = nums.rbegin() ; itr != nums.rend() ; itr++) {
        cout<<*(itr)<<" ";
    }
    // 5 4 3 2 1
    cout<<endl;

    // ****************

    // By Value : for(auto it : arr), works on a copy, modifications won't affect the original.
    // By Reference : for(auto &it : arr), you can modify elements directly.

    // by value : for-each loop
    // a new copy of nums is generated and changes are made to the copy only
    for(int it : nums) {
        it++;
    }
    // check on print
    for(int it : nums) {
        cout<<it<<" ";
    }
    // 1 2 3 4 5 
    cout<<endl;

    // by reference : for-each loop
    // changes are made to the nums vector only as passed by reference
    for(int& it : nums) {
        it++;
    }
    // check on print
    for(int it : nums) {
        cout<<it<<" ";
    }
    // 2 3 4 5 6
    cout<<endl;

    return 0;
}