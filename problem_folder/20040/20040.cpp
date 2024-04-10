#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// globals
set<int> oddDegreeVertex;

// functions
void updateDegreeVertex(int v, bool isOddDegree);

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> stepInfo(m);
    vector<int> degreeInfo(n, 0);
    for(int i = 0; i < m; i++){
        cin >> stepInfo[i].first >> stepInfo[i].second;
    }

    // solving
    bool success = false;
    for(int i = 0; i < m; i++){
        int v = stepInfo[i].first, w = stepInfo[i].second;
        degreeInfo[v] += 1;
        degreeInfo[w] += 1;
        // odd degree -> add in degreeInfo[] / even degree -> erase in degreeInfo[] if it contains
        updateDegreeVertex(v, degreeInfo[v] % 2 != 0);
        updateDegreeVertex(w, degreeInfo[w] % 2 != 0);

        if(oddDegreeVertex.size() == 0 || oddDegreeVertex.size() == 2){
            // when answer found
            cout << i + 1;
            success = true;
            break;
        }
    }

    // output
    if(!success){
        cout << 0;
    }
	return 0;
}

void updateDegreeVertex(int v, bool isOddDegree){
    if(isOddDegree) {
        oddDegreeVertex.insert(v);
    }else{// if(oddDegreeVertex.find(v) != oddDegreeVertex.end()) {
        oddDegreeVertex.erase(v);
    }
    return;
}