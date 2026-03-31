
// Depth First Search (DFS) 
// traversal starting from vertex 0

#include <iostream>
#include <vector>
using namespace std;


void depthFirstSearch(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfs) {
    visited[node] = true;
    dfs.push_back(node);
    for(auto it : adj[node]) {
        if(!visited[it]) {
            depthFirstSearch(it,adj,visited,dfs);
        }
    }
}

// Time Complexity: O(V) + O(2*E)
//                  dfs   visited  stack space
// Space Complexity: O(N) + O(N) + O(N) = O(N)
// additional amount of space required for recursion stack.

vector<int> dfs(vector<vector<int>>& adj) {
    int V = adj.size();
    // 0-based Indexing
    vector<bool> visited(V,false);

    vector<int> dfs;
    
    int src = 0;
    
    depthFirstSearch(src,adj,visited,dfs);

    return dfs;
}


int main()
{
    return 0;
}