#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Adjacency Matrix Function
void adjacency_Matrix() {
    int n, m;
    cin >> n >> m;

    int direction;
    cin >> direction; // 1 - undirected, 0 - directed

    int **adj = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        adj[i] = new int[n + 1];
    }

    for(int i = 0 ; i<=n ; i++){
        for(int j = 0 ; j<=n ;j++){
             adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Edge u -> v
        if (direction == 1) {
            adj[v][u] = 1; // Edge v -> u for undirected graph
        }
    }

    // Print adjacency matrix
    cout << "Adjacency Matrix\n  ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i <= n; i++) delete[] adj[i];
    delete[] adj;
}

// Add edge to adjacency list
void add_Edge(vector<vector<int>> &adj_list, int u, int v, bool direction) {
    adj_list[u].push_back(v);
    if (direction == true) {
        adj_list[v].push_back(u);
    }
}

// Print adjacency list
void print_list(const vector<vector<int>> &adj_list) {
    cout << "Adjacency List\n";
    for (int i = 0; i < adj_list.size(); i++) {
        cout << i << " -> ";
        if (adj_list[i].empty()) {
            cout << "{}";
        } else {
            for (auto j : adj_list[i]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

// BFS Traversal
void BFS(const vector<vector<int>> &adj_list, vector<bool> &visited, int start_Node) {
    queue<int> q;
    q.push(start_Node);
    visited[start_Node] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";

        for (auto i : adj_list[top]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// DFS Traversal
void DFS(const vector<vector<int>> &adj_list, vector<bool> &visited, int Node) {
    cout << Node << " ";
    visited[Node] = true;

    for (auto i : adj_list[Node]) {
        if (!visited[i]) {
            DFS(adj_list, visited, i);
        }
    }
}

int main() {
  
    // adjacency_Matrix();

    // Adjacency List Example
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_Edge(adj_list, u, v, true); 
    }

    print_list(adj_list);

    vector<bool> visited(n, false);

    cout << "BFS Traversal:\n";
    for (int i = 0; i < n; i++) { // edge case : if there is a disconnected graph that mean's multiple components
        if (!visited[i]) {
            BFS(adj_list, visited, i);
        }
    }

    cout << "\nDFS Traversal:\n";
    fill(visited.begin(), visited.end(), false); // fill with false again
    for (int i = 0; i < n; i++) { // edge case : if there is a disconnected graph that mean's multiple components
        if (!visited[i]) {
            DFS(adj_list, visited, i);
        }
    }

    return 0;
}
