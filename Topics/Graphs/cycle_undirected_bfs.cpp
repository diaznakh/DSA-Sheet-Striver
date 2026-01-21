#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS to detect cycle starting from a source node
bool bfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    // Queue stores pairs of (current node, parent node)
    queue<pair<int, int>> q;
    
    visited[src] = true;
    q.push({src, -1}); // -1 means no parent
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            }
            // If neighbor is visited and is NOT the parent, we found a cycle
            else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

// Main function to check cycle in entire graph (handles disconnected components)
bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V + 1, false);
    
    // Check for all components
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> adj(V + 1);
    
    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
    
    if (hasCycle(V, adj)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }
    
    return 0;
}
