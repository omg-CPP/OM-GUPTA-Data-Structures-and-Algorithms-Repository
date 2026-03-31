#include <iostream>
#include <vector>
using namespace std;

// printing array of vectors
void printAdjacencyList(vector<int> adj[], int n) {
    cout<<"Adjacency List : "<<endl;
    for(int i = 0 ; i <= n ; i++) {
        cout<<i<<" :: ";
        for(int j = 0 ; j < adj[i].size() ; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// printing vector of vectors
void printAdjacencyList(vector<vector<int>>& adj) {
    for(int i = 0 ; i < adj.size() ; i++) {
        cout<<i<<" :: ";
        for(int j = 0 ; j < adj[i].size() ; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

// T.C. = O(N)
// S.C. = O(2*E) for Undirected Graph as every edge has two nodes
// S.C. = O(E) for Directed Graph

int main()
{
    // n = no of nodes or vertex
    // m = no of edges
    int n,m;
    cout<<"Enter nodes and edges : ";
    cin>>n>>m;
    
    // Create adjacency list as array of vectors
    // CORRECT: Dynamically allocated array of vectors
    vector<int>* adj = new vector<int>[n+1];
    // vector<vector<int>> adj(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        // u --- v :: Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph

        // u ---> v :: Directed Graph
        // adj[u].push_back(v);
    }

    printAdjacencyList(adj,n);
    // printAdjacencyList(adj);

    return 0;
}

// ************** For Undirected Garph ****************

// Enter nodes and edges : 5 6

// 2 1
// 1 3
// 2 4
// 3 4
// 2 5
// 4 5

// Adjacency List : 
// 0 :: 
// 1 :: 2 3 
// 2 :: 1 4 5 
// 3 :: 1 4 
// 4 :: 2 3 5 
// 5 :: 2 4 

// ************** For Directed Garph ****************

// Enter nodes and edges : 5 6

// 2 1
// 1 3
// 2 4
// 3 4
// 2 5
// 4 5

// Adjacency List : 
// 0 ::
// 1 :: 3
// 2 :: 1 4 5
// 3 :: 4
// 4 :: 5
// 5 ::