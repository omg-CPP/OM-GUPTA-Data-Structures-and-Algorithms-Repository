
// Breadth First Search :: BFS
// traversal starting from vertex 0

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// a node goes once in the queue
// T.C. = N + 2*M = O(V) + O(2*E)

// S.C. = O(V) + O(V) + O(V) = O(V)
//       visted queue   bfs
vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    // 0-based Indexing
    vector<bool> visited(V,false);

    vector<int> bfs;
    
    queue<int> q;
    int src = 0;
    visited[src] = true;
    q.push(src);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // visit all the unvisited
        // neighbours of current node
        for(auto it : adj[node]) {
            if(!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return bfs;
}


int main()
{
    return 0;
}