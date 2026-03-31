// Leetcode : 547

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// The key fix is using 0-indexed iteration (0 to V-1) 

#include <iostream>
#include <vector>
using namespace std;

void depthFirstSearch(int node, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[node] = 1;
    for(auto it : adjList[node]) {
        if(!visited[it]) {
            depthFirstSearch(it,adjList,visited);
        }
    }
}

//        vis    rec stack
// S.C. = O(N) + O(N)
//        dfs call overall dfs
// T.C. = O(N)  +  O(V + 2*E)

int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    // creating our adjacenecy list from adjacency matrix
    // This alternative uses vector<vector<int>> instead of dynamic array allocation, which is safer and more idiomatic in C++.
    vector<vector<int>> adjList(V);
    for(int i = 0 ; i < V ; i++) {
        for(int j = 0 ; j < V ; j++) {
            if(isConnected[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
            }
        }
    }

    vector<int> visited(V,0); 
    // Initialize visited vector with size V and all zeros
    int cnt = 0;
    for(int i = 0 ; i < V ; i++) {
        if(!visited[i]) {
            cnt++;
            depthFirstSearch(i,adjList,visited);
        }
    }
    return cnt;
}

int main()
{
    return 0;
}