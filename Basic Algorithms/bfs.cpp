#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>

using namespace std;

// functions
int readFile(vector<vector<int>> &graph);
void printGraph(vector<vector<int>> &graph);
void bfs(int n, vector<int> &visited, vector<vector<int>> &graph);

// main()
int main(){
    // member variables
    vector<vector<int>> graph;
    
    // read file
    int n = readFile(graph);
    vector<int> visited(n, 0);
    printGraph(graph);
    
    // bfs
    bfs(n, visited, graph);
    return 0;
}

// functions
int readFile(vector<vector<int>> &graph){
    fstream fs;
    int n, V;

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
    return n;
}

void printGraph(vector<vector<int>> &graph){
    cout << "Graph Info -\n";
    for(int i = 0; i < graph.size(); i++){
        cout << "vertex " << i+1 << " - ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void bfs(int n, vector<int> &visited, vector<vector<int>> &graph){
    int idx;
    queue<int> q;
    cout << "start bfs\n";
    // 1번부터 bfs 시작
    q.push(1);
    while(!q.empty()){
        do{
            idx = q.front();
            q.pop();
        }while(!visited[idx - 1]);
        visited[idx - 1] = 1;
        cout << "visited - " << idx << "\n";
        for(int i = 0; i < graph[idx - 1].size(); i++){
            int curIdx = graph[idx - 1][i];
            if(!visited[curIdx - 1]){
                q.push(curIdx);
            }
        }
    }
    return;
}