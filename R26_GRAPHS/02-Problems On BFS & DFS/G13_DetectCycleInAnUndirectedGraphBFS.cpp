// Undirected Graph Cycle : GFG

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS SOLUTION
//              sum of all adjacent nodes = sum of degree
// T.C. = O(N + 2*E) + O(N) {Component}
//        queue  visited
// S.C. = O(N) + O(N)

bool detect(int src, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto& adjacentNode : adjList[node]) {
            if(!visited[adjacentNode]) {
                visited[adjacentNode] = 1;
                q.push({adjacentNode,node});
            }
            else if(parent != adjacentNode) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    // Converting edges[][] into adjacency List
    vector<vector<int>> adjList(V);
    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
    // 0-Based Indexing
    vector<int> visited(V);
    // Note: The graph can have multiple component.
    for(int i = 0 ; i < V ; i++) {
        if(!visited[i]) {
            if(detect(i,adjList,visited)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}