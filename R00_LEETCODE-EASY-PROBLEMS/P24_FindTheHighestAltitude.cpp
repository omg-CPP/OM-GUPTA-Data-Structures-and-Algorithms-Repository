// Leetcode : 1732 (EASY)

// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

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
    // using vector
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitudes(n+1,0);
        altitudes[0] = 0;
        for(int i = 1 ; i < n+1 ; i++) {
            altitudes[i] = altitudes[i-1] + gain[i-1];
        }
        return *max_element(altitudes.begin(),altitudes.end());
    }

    // using variable
    int largestAltitude_(vector<int>& gain) {
        int currAltitude = 0;
        int maxAltitude = currAltitude;
        for(int i = 0 ; i < gain.size() ; i++) {
            currAltitude += gain[i];
            maxAltitude = max(maxAltitude,currAltitude);
        }
        return maxAltitude;
    }
};

int main()
{
    return 0;
}