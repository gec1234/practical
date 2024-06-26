#include<iostream>
#include<climits> 
using namespace std;
const int SIZE = 6;
int count = 0;
int miniDist(int distance[], bool Tset[]) {
    count++;
    int minimum = INT_MAX, ind;
              
    for(int k = 0; k < SIZE; k++) {
        count++;
        if(Tset[k] == false && distance[k] <= minimum) {
            count++;
            minimum = distance[k];
            ind = k;
        }
    }
    count++;
    return ind;
}
void DijkstraAlgo(int graph[SIZE][SIZE], int src) {
    count++;
    int distance[SIZE];                            
    bool Tset[SIZE];
    for(int k = 0; k < SIZE; k++) {
        count++;
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    count++;
    distance[src] = 0;   
    for(int k = 0; k < SIZE; k++) {
        count++;
        int m = miniDist(distance, Tset); 
        Tset[m] = true;
        count++;
        for(int k = 0; k < SIZE; k++) {
            count++;
            if(!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k]){
                count++;
                distance[k] = distance[m] + graph[m][k];
            }
        }
        count++;
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for(int k = 0; k < SIZE; k++) {
        count++; 
        char str = 65 + k; 
        cout << str << "\t\t\t" << distance[k] << endl;
    }
    count++;
}
int main() {
    int input;
    cout << "Enter a number: ";
    cin >> input;

    int graph[SIZE][SIZE] = {
        {0, 7, 9, input, input, 14},
        {7, 0, 10, 15, input, input},
        {9, 10, 0, 11, input, 2},
        {input, 15, 11, 0, 6, input},
        {input, input, input, 6, 0, 9},
        {14, input, 2, input, 9, 0}
    };
    DijkstraAlgo(graph, 0);
    cout << "Total count: " << count << endl;
    return 0;                           
}
