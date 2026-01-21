#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>>& adj, int u, int v, bool undirected = true) {
    adj[u].push_back(v);
    if (undirected) {
        adj[v].push_back(u);
    }
}

// Function to print the adjacency list
void printGraph(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Vertex " << i << ":";
        for (int neighbor : adj[i]) {
            cout << " -> " << neighbor;
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E)) return 0;

    // Adjacency list with V+1 to handle 1-based indexing if needed
    vector<vector<int>> adj(V + 1);

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        char x;
        cin >> u >> v >> x;
        if(x == 't'){
            addEdge(adj, u, v);
        }
        else{
            addEdge(adj, u, v, false);
        }
    }

    cout << "\nAdjacency List:" << endl;
    printGraph(adj);

    return 0;
}
