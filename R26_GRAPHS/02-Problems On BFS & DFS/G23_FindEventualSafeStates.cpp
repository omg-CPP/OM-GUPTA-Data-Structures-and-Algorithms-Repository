// Leetcode : 802

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(V + E)
// S.C. = O(V) + O(V) + O(V) = O(V)

bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& mark) {
    visited[node] = 1;
    pathVisited[node] = 1;

    // traverse for adjacent Nodes

    for(auto& adjNode : graph[node]) {
        // when the node is not visited
        if(!visited[adjNode]) {
            if(dfsCheck(adjNode,graph,visited,pathVisited,mark) == true) {
                return true;
            }
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if(pathVisited[adjNode]) {
            return true;
        }
    }

    // marking after checking all the neighbours led to safe states
    mark[node] = 1;
    pathVisited[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    // graph is the adjacency list
    int V = graph.size();
    vector<int> visited(V,0);
    vector<int> pathVisited(V,0);
    vector<int> mark(V,0);
    vector<int> safeNodes;

    for(int i = 0 ; i < V ; i++) {
        if(!visited[i]) {
            dfsCheck(i,graph,visited,pathVisited,mark);
        }
    }

    for(int i = 0 ; i < V ; i++) {
        if(mark[i] == 1) {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}

int main()
{
    return 0;
}
