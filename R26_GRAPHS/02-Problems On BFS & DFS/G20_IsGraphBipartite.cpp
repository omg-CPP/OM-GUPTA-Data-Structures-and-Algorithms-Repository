// Leetcode : 785

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Solution

// colors a individual component
bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
    // graph is the adjacency list only
    int V = graph.size();
    queue<int> q;
    q.push(start);
    
    color[start] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto& adjNode : graph[node]) {
            // if the adjacent node is yet not colored
            if(color[adjNode] == -1) {
                color[adjNode] = !color[node];
                q.push(adjNode);
            }
            // if the adjacent guy has the same color
            // someone did color it on some other path
            else if(color[adjNode] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color; // visited array
    color.resize(V,-1);
    // checking for multiple components
    for(int i = 0 ; i < V ; i++) {
        if(color[i] == -1) {
            if(check(i,graph,color) == false) {
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
