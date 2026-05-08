// Directed Graph Cycle : GFG

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(V + E)
// S.C. = O(V) + O(V)

bool dfsCheck(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& pathVisited) {
    visited[node] = 1;
    pathVisited[node] = 1;

    // traverse for adjacent Nodes

    for(auto& adjNode : adjList[node]) {
        // when the node is not visited
        if(!visited[adjNode]) {
            if(dfsCheck(adjNode,adjList,visited,pathVisited) == true) {
                return true;
            }
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if(pathVisited[adjNode]) {
            return true;
        }
    }

    pathVisited[node] = 0;
    return false;
}

bool isCyclic(int V, vector<vector<int>>& edges) {
    // Converted into the Adjacency List
    vector<vector<int>> adjList(V);
    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        // directed graph
        adjList[u].push_back(v);
    }

    vector<int> visited(V,0);
    vector<int> pathVisited(V,0);

    for(int i = 0 ; i < V ; i++) {
        if(!visited[i]) {
            if(dfsCheck(i,adjList,visited,pathVisited) == true) {
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
