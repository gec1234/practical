#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int> > &graph, int v, vector<bool> &visited, int pathCount) {
    if (visited[v]) {
        return false;
    }
    if (pathCount == graph.size() - 1) {
        return graph[v][0]; // Check if there's an edge from v to 0
    }
    return true;
}

bool findHamiltonianUtil(vector<vector<int> > &graph, vector<bool> &visited, vector<int> &path, int pathCount) {
    if (pathCount == graph.size()) {
        return graph[path[pathCount - 1]][0];
    }
    for (int i = 0; i < graph.size(); i++) {
        if (isSafe(graph, i, visited, pathCount)) {
            visited[i] = true;
            path[pathCount] = i;
            if (findHamiltonianUtil(graph, visited, path, pathCount + 1)) {
                return true;
            }
            visited[i] = false;
            path[pathCount] = -1;
        }
    }
    return false;
}

void printSolution(const vector<int> &path) {
    cout << "Hamiltonian Cycle Found: ";
    for (size_t i = 0; i < path.size(); i++) {
        if (path[i] != -1) {
            cout << path[i] << " ";
        }
    }
    cout << endl;
}


int main() {
    int num_cities;
    cout << "Enter the number of cities: ";
    cin >> num_cities;
    vector<vector<int> > graph(num_cities, vector<int>(num_cities, 0));
    cout << "Enter the distance matrix (row by row):\n";
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {
            cin >> graph[i][j];
        }
    }
    vector<bool> visited(num_cities, false);
    vector<int> path(num_cities, -1);
    path[0] = 0;
    if (findHamiltonianUtil(graph, visited, path, 1)) {
        printSolution(path);
    } else {
        cout << "No Hamiltonian Cycle Found" << endl;
    }
    return 0;
}
