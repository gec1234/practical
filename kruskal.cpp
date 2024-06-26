#include <iostream>
#include <vector>
#include <algorithm>
#define edge pair<int, int> // holds edge value u,v
using namespace std;
int count = 0; // Global variable count
class Graph
{
public:
    vector<pair<int, edge> > G; // here first data will hold weight in G
    vector<pair<int, edge> > T; // T will hold final mst
    int *parent;
    int V;
    int mstSum; // Moved mstSum from global scope to class scope
    Graph(int V)
    {
        parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;  
        }
        mstSum = 0; // Initialize mstSum in constructor
    }
    int find_set(int i)
    { // find_set method is used for finding parent of a vertex
         // Increment global count for each step
        if (i == parent[i])
       {
            return i;
            
        }
        return find_set(parent[i]);
        
    }
    void union_set(int u, int v)
    { // union_set method is used when we join two vertices
        parent[u] = parent[v];
        
    }
    void AddWeightedEdge(int u, int v, int wt)
    {
        G.push_back(make_pair(wt, edge(u, v)));
        
    }
    void kruskal()
    {
        int u1, v1;
        sort(G.begin(), G.end()); // ascending order sorting of weights
        for (int i = 0; i < G.size(); i++)
        {
             // Increment global count for each step
            u1 = find_set(G[i].second.first);
            v1 = find_set(G[i].second.second);
            if (u1 != v1)
            {
                mstSum += G[i].first;
                T.push_back(G[i]); // add the edge
                union_set(u1, v1);
            }
        }
        
    }
    void printMst()
    {
        cout << "Edge: Weight" << endl;
        for (int i = 0; i < T.size(); i++)
        {
            cout << T[i].second.first << "-" << T[i].second.second << ":" << T[i].first;
            cout << endl;
            
        }
        cout << "MST Sum is : " << mstSum << endl;
        cout << "Time complexity is: " << ::count  << endl; // Displaying the global count
    }
}
int main()
{
    Graph g(6);
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 4);
    g.AddWeightedEdge(2, 0, 4);
    g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 4);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 3);
    g.kruskal();
    g.printMst();
    return 0;
}
