
#include <iostream>
#include <vector>
using namespace std;


void printAdjancencyMatrix(vector<vector<int>>& adj) {
    for(int i = 0 ; i < adj.size() ; i++) {
        for(int j = 0 ; j < adj[i].size() ; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

// T.C. = O(N)
// S.C. = O(N^2)

int main()
{
    // n = no of nodes or vertex
    // m = no of edges
    int n,m;
    cout<<"Enter nodes and edges : ";
    cin>>n>>m;

    // graph here

    // Create a 2D vector with dimensions (n+1) x (n+1)
    vector<vector<int>> adj(n+1, vector<int>(n+1,0));

    // Now you can use adj like a 2D array
    for(int i = 0 ; i < m ; i++) {
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }

    printAdjancencyMatrix(adj);
    
    return 0;
}

// Enter nodes and edges : 5 6

// 2 1
// 1 3
// 2 4
// 3 4
// 2 5
// 4 5

// 0 0 0 0 0 0 
// 0 0 1 1 0 0 
// 0 1 0 0 1 1 
// 0 1 0 0 1 0
// 0 0 1 1 0 1 
// 0 0 1 0 1 0