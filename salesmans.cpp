#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int distance(vector<vector<int>>& graph, int i, int j) {
    return graph[i][j];
}
int tsp(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[0] = true; // Start at city 0
    int min_cost = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_dist = INT_MAX;
        int next_city = 0;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance(graph, i, j) < min_dist) {
                min_dist = distance(graph, i, j);
                next_city = j;
            }
        }
        visited[next_city] = true;
        min_cost += min_dist;
    }

    min_cost += distance(graph, n - 1, 0);
    return min_cost;
}

int main() {
    int num_cities;
    cout << "Enter the number of cities: ";
    cin >> num_cities;
    vector<vector<int>> graph(num_cities, vector<int>(num_cities, 0));
    cout << "Enter the distance matrix (row by row):\n";
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {
            cin >> graph[i][j];
        }
    }
    int total_distance = tsp(graph);
    cout << "Minimum cost of travel: " << total_distance << endl;

    return 0;
}
