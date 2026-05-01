
// Undirected Graph Cycle : GFG

#include <iostream>
#include <vector>
using namespace std;

//       
// T.C. = O(N + 2*E) + O(N) {component}
//  rec stack space  visited
// S.C. = O(N)   +   O(N) 


bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adjList) {
    visited[node] = 1;
    for(auto& adjacentNode : adjList[node]) {
        if(!visited[adjacentNode]) {
            if(dfs(adjacentNode,node,visited,adjList) == true) {
                return true;
            }
        }
        else if(adjacentNode != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adjList(V);
    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
    // 0-Based Indexing
    vector<int> visited(V);
    for(int i = 0 ; i < V ; i++) {
        if(!visited[i]) {
            if(dfs(i,-1,visited,adjList)) {
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
