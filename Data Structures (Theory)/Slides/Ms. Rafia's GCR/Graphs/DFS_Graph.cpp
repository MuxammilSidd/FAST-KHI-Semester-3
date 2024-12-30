#include <iostream>
#include <vector>
using namespace std;

// Recursive function for DFS traversal
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

// Main DFS function that initializes the visited array
// and call DFSRec
void DFS(vector<vector<int>> &adj, int s) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}

// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main() {
    int V = 5; 
    vector<vector<int>> adj(V);

    // Add edges
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (int i = 0; i < edges.size(); i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj, s); // Perform DFS starting from the source vertex

    return 0;
}
