// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>

#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n;

int dfs(vector<vector<int>> &, vector<int>&, int);
int main(){
    fastIO
    
    int V;
    vector<vector<int>> graph;
    fstream fs;
    
    // inputs
    fs.open("./test.txt", ios::in);
    if(!fs){    // if fails
        cerr << "Error!\n";
    }
    fs >> n;
    for(int i = 0; !fs.eof(); i++){
        fs >> V;
        graph.push_back({});
        for(int j = 0; j < V; j++){
            graph[i].push_back(0);
            fs >> graph[i][j];
        }
    }
    fs.close();


    // output
    cout << "Graph info - \n";
    for(int i = 0; i < n; i++){
        cout << "Vertex " << i+1 << " - ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "DFS result -\n";
    vector<int> visited(n, 0);
    dfs(graph, visited, 1);

    return 0;
}

int dfs(vector<vector<int>> &graph, vector<int>& visited, int n){
    cout << "Vertex " << n << "\n";
    visited[n - 1] = 1;

    for(int i = 0; i < graph[n - 1].size(); i++){
        int idx = graph[n - 1][i];
        if(!visited[idx - 1]){
            dfs(graph, visited, idx);
        }
    }
    return 0;
}