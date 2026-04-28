// GFG

#include <iostream>
#include <vector>
using namespace std;

// ********************************* Memoization DP ********************************

int fun_Memoization(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if(day == 0) {
        int maxi = 0;
        for(int task = 0 ; task < 3 ; task++) {
            if(task != last) {
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) {
        return dp[day][last];
    }

    int maxi = 0;
    for(int task = 0 ; task < 3 ; task++) {
        if(task != last) {
            int point = points[day][task] + fun_Memoization(day-1,task,points,dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return fun_Memoization(n-1,3,arr,dp);
}

int main()
{
    return 0;
}