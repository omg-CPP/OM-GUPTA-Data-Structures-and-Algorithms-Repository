// Leetcode : 1436 (EASY)

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
    // T.C. = O(N)
    // S.C. = O(map)
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        for(auto& path : paths) {
            string source = path[0];
            mp[source] = 1;
        }
        for(auto& path : paths) {
            string dest = path[1];
            if(mp[dest] != 1) {
                return dest;
            }
        }
        return "";
    }
};

int main()
{
    return 0;
}