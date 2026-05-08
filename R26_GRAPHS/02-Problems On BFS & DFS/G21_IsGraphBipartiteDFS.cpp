// Leetcode : 785

#include <iostream>
#include <vector>
using namespace std;

// DFS SoLution

// T.C. = O(V + 2*E)
// S.C. = O(V)

bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
    color[node] = col;
    for(auto& adjNode : graph[node]) {
        // if the adjacent node is yet not colored
        if(color[adjNode] == -1) {
            if(dfs(adjNode,!col,graph,color) == false) {
                return false;
            }
        }
        // if the adjacent guy has the same color
        else if(color[adjNode] == color[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    // graph is the adjacency list
    int V = graph.size();
    vector<int> color;
    color.resize(V,-1);
    // initial color
    int start = 0;
    // writing code for multiple components
    for(int i = 0 ; i < V ; i++) {
        if(color[i] == -1) {
            if(dfs(i,start,graph,color) == false) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    return 0;
}
