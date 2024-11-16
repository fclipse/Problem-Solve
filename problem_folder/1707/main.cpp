#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// functions
bool isBipartite(int v, bool prevColor, vector<bool> &graphColor, vector<bool> &visited, vector<vector<int>> &graph);
bool dfs(int v, )

int main() {
	fastio;
    int k, vertexNum, edgeNum;
    cin >> k;
    while(k-- > 0){
        cin >> vertexNum >> edgeNum;
        vector<bool> graphColor(vertexNum + 1, false);
        vector<bool> visited(vertexNum + 1, false);
        vector<vector<int>> graph(vertexNum + 1);
        for (int i = 0; i < edgeNum; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(isBipartite(1, false, graphColor, visited, graph)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
	return 0;
}

bool isBipartite(int v, bool prevColor, vector<bool> &graphColor, vector<bool> &visited, vector<vector<int>> &graph){
    if(!visited[v]){
        graphColor[v] = !prevColor;
        visited[v] = true;
        for (int i = 0; i < graph[v].size(); i++){
            bool result = isBipartite(graph[v][i], graphColor[v], graphColor, visited, graph);
            if(!result) return result;
        }
    }else{
        if(graphColor[v] == prevColor) return false;
    }
    return true;
}