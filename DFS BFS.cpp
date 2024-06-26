1)DFS:
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> stk;
    stk.push(start);
    visited[start] = true;

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); ++i) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (from to):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // If the graph is undirected, uncomment the line below
        // graph[v].push_back(u);
    }

    int start;
    cout << "Enter the starting node for DFS: ";
    cin >> start;
    cout << "Depth First Traversal starting from node " << start << ": ";
    dfs(graph, start);
    cout << endl;

    return 0;
}

2) BFS:
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Graph {
    int V; // Number of vertices
    // Pointer to an array containing adjacency lists
    vector<vector<int>> adj;

public:
    Graph(int V); // Constructor
    // Function to add an edge to the graph
    void addEdge(int v, int w);
    // BFS traversal of the vertices reachable from s
    void BFS(int s);
};
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list
}
void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
    // Create a queue for BFS
    queue<int> q;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        s = q.front();
        cout << s << " ";
        q.pop();
        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int start_vertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start_vertex;
    cout << "BFS starting from vertex " << start_vertex << ": ";
    g.BFS(start_vertex);

    return 0;
}
