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
    // vector<int> nums = {1,2,3,4,5};
    // int n = nums.size();

    // // ****************

    // // for loop :: most common
    // for(int i = 0 ; i < n ; i++) {
    //     cout<<nums[i]<<" ";
    // }
    // // 1 2 3 4 5 
    // cout<<endl;


    // // while loop
    // int i = 0;
    // while(i < n) {
    //     cout<<nums[i]<<" ";
    //     i++;
    // }
    // // 1 2 3 4 5 
    // cout<<endl;

    // // do-while loop
    // i = 0;
    // do {
    //     cout<<nums[i]<<" ";
    //     i++;
    // }
    // while(i < n);
    // // 1 2 3 4 5 
    // cout<<endl;

    // // ****************

    // // for-each loop
    // for(int& it : nums) {
    //     cout<<it<<" ";
    // }
    // // 1 2 3 4 5 
    // cout<<endl;

    // // using auto in for-each loop :: commonly used in CP
    // for(auto& it : nums) {
    //     cout<<it<<" ";
    // }
    // // 1 2 3 4 5 
    // cout<<endl;

    // // ****************

    // // using itertor
    // for(vector<int>::iterator it = nums.begin() ; it != nums.end() ; it++) {
    //     cout<<*(it)<<" ";
    // }
    // // 1 2 3 4 5 
    // cout<<endl;

    // // using auto in itertor
    // for(auto it = nums.begin() ; it != nums.end() ; it++) {
    //     cout<<*(it)<<" ";
    // }
    // // 1 2 3 4 5 
    // cout<<endl;

    // // ****************

    // // printing reverse array
    // for(int i = n-1 ; i >= 0 ; i--) {
    //     cout<<nums[i]<<" ";
    // }
    // // 5 4 3 2 1 
    // cout<<endl;

    // // using reverse-iterator
    // for(vector<int>::reverse_iterator itr = nums.rbegin() ; itr != nums.rend() ; itr++) {
    //     cout<<*(itr)<<" ";
    // }
    // // 5 4 3 2 1 
    // cout<<endl;

    // // using auto in reverse-itertor
    // for(auto itr = nums.rbegin() ; itr != nums.rend() ; itr++) {
    //     cout<<*(itr)<<" ";
    // }
    // // 5 4 3 2 1
    // cout<<endl;

    // // ****************

    // // By Value : for(auto it : arr), works on a copy, modifications won't affect the original.
    // // By Reference : for(auto &it : arr), you can modify elements directly.

    // // by value : for-each loop
    // // a new copy of nums is generated and changes are made to the copy only
    // for(int it : nums) {
    //     it++;
    // }
    // // check on print
    // for(int it : nums) {
    //     cout<<it<<" ";
    // }
    // // 1 2 3 4 5 
    // cout<<endl;

    // // by reference : for-each loop
    // // changes are made to the nums vector only as passed by reference
    // for(int& it : nums) {
    //     it++;
    // }
    // // check on print
    // for(int it : nums) {
    //     cout<<it<<" ";
    // }
    // // 2 3 4 5 6
    // cout<<endl;

    // ******************************************************

    // 2D Vectors

    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};

    // deep copy (New copy is generated)
    // copy1 is basically a deep copy
    vector<vector<int>> copy1 = grid;

    // eg. changes made to copy1 won't be reflected in grid
    copy1[1][0] = 76;

    for(int i = 0 ; i < grid.size() ; i++) {
        for(int j = 0 ; j < grid[0].size() ; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 4 5 6 
    // 7 8 9 

    cout<<"------------"<<endl;

    for(int i = 0 ; i < copy1.size() ; i++) {
        for(int j = 0 ; j < copy1[0].size() ; j++) {
            cout<<copy1[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3 
    // 76 5 6 
    // 7 8 9 

    cout<<"------------"<<endl;

    // shallow copy (reference) -> No new copy is created
    vector<vector<int>>& copy2 = grid;
    // eg. changes made to copy2 will be reflected in grid
    copy2[0][1] = 90;

    for(int i = 0 ; i < grid.size() ; i++) {
        for(int j = 0 ; j < grid[0].size() ; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 90 3 
    // 4 5 6 
    // 7 8 9

    cout<<"------------"<<endl;

    for(int i = 0 ; i < copy2.size() ; i++) {
        for(int j = 0 ; j < copy2[0].size() ; j++) {
            cout<<copy2[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 90 3
    // 4 5 6
    // 7 8 9

    cout<<"------------"<<endl;

    // Loops In 2D Vectors...
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    
    // ✅ 1. Most Common Styled for loop (row-wise)
    for(int i = 0 ; i < mat.size() ; i++) {
        for(int j = 0 ; j < mat[i].size() ; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<"------------"<<endl;

    // ✅ 2. while loop
    int i = 0;
    while(i < mat.size()) {
        int j = 0;
        while(j < mat[i].size()) {
            cout<<mat[i][j]<<" ";
            j++;
        }
        i++;
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<"------------"<<endl;

    // ✅ 3. column wise printing
    for(int j = 0 ; j < 3 ; j++) {
        for(int i = 0 ; i < 3 ; i++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    // 1 4 7
    // 2 5 8
    // 3 6 9

    cout<<"------------"<<endl;

    // ✅ 4. range based loops (for-each loop) : reference
    for(auto& row : mat) {
        for(auto& val : row) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<"------------"<<endl;

    // ✅ 5. range based loops (for-each loop) : copy
    for(auto row : mat) {
        for(auto val : row) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9

    cout<<"------------"<<endl;

    // ✅ 6. range based loops (for-each loop) : reference (modification)
    for(auto& row : mat) {
        for(auto& val : row) {
            val -= 1; // modifies original mat
        }
    }

    // printing
    for(auto& row : mat) {
        for(auto& val : row) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    // 0 1 2
    // 3 4 5
    // 6 7 8

    cout<<"------------"<<endl;

    // ✅ 7. using iterators
    for(vector<vector<int>>::iterator it_row = mat.begin() ; it_row != mat.end() ; it_row++) {
        for(vector<int>::iterator it_col = it_row->begin() ; it_col != it_row->end() ; it_col++) {
            cout<<(*it_col)<<" ";
        }
        cout<<endl;
    }
    // 0 1 2
    // 3 4 5
    // 6 7 8

    cout<<"------------"<<endl;

    // ✅ 8. using auto with iterators (cleaner)
    for(auto it_row = mat.begin() ; it_row != mat.end() ; it_row++) {
        for(auto it_col = it_row->begin() ; it_col != it_row->end() ; it_col++) {
            cout<<(*it_col)<<" ";
        }
        cout<<endl;
    }
    // 0 1 2
    // 3 4 5
    // 6 7 8

    cout<<"------------"<<endl;

    // ✅ 9. reverse traversal
    for(int i = mat.size()-1 ; i >= 0 ; i--) {
        for(int j = mat[i].size()-1 ; j >= 0 ; j--) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    // 8 7 6
    // 5 4 3
    // 2 1 0

    cout<<"------------"<<endl;

    // ✅ 10. reverse traversal using reverse iterators 
    for(vector<vector<int>>::reverse_iterator it_row = mat.rbegin() ; it_row != mat.rend() ; it_row++) {
        for(vector<int>::reverse_iterator it_col = it_row->rbegin() ; it_col != it_row->rend() ; it_col++) {
            cout<<(*it_col)<<" ";
        }
        cout<<endl;
    }
    // 8 7 6
    // 5 4 3
    // 2 1 0

    cout<<"------------"<<endl;

    // ✅ 11. using auto with reverse iterators (cleaner)
    for(auto it_row = mat.rbegin() ; it_row != mat.rend() ; it_row++) {
        for(auto it_col = it_row->rbegin() ; it_col != it_row->rend() ; it_col++) {
            cout<<(*it_col)<<" ";
        }
        cout<<endl;
    }
    // 8 7 6
    // 5 4 3
    // 2 1 0

    cout<<"------------"<<endl;

    // ✅ 12. for_each with Lambda (Advanced STL) -> Functional-style programming
    for_each(mat.begin(), mat.end(), [](vector<int>& row) {
        for_each(row.begin(), row.end(), [](int& val) {
            cout << val << " ";
        });
        cout<<endl;
    });
    // 0 1 2
    // 3 4 5
    // 6 7 8

    cout<<"------------"<<endl;

    // ✅ 13. pointer based loop in 1D Array
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* p = arr;
    for(int i = 0 ; i < n ; i++) {
        cout<<(*p)<<" ";
        p++;
    }
    // 1 2 3 4 5
    cout<<endl;

    cout<<"------------"<<endl;

    for(int* ptr = arr ; ptr < arr+n ; ptr++) {
        cout<<(*ptr)<<" ";
    }
    // 1 2 3 4 5
    cout<<endl;

    cout<<"------------"<<endl;

    return 0;
}