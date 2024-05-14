#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000002

using namespace std;

// globals
int execCount[SIZE] = {0};
int _parent[SIZE] = {0};
int routes[SIZE] = {0};

int main(){
	fastio;
    int n;
    cin >> n;
    
    // solving
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int targets[3] = {curr / 3, curr / 2, curr - 1};
        bool validateExp[3] = {curr % 3 == 0, curr % 2 == 0, true};
        bool isOverZero[3] = {curr / 3 > 0, curr / 2 > 0, curr - 1 > 0};

        for (int i = 0; i < 3; i++){
            if(validateExp[i] && isOverZero[i]){
                int target = targets[i];
                if(execCount[target] == 0 || execCount[target] > execCount[curr] + 1){
                    execCount[target] = execCount[curr] + 1;
                    _parent[target] = curr;
                    q.push(target);
                }    
            }
        }
    }
    
    routes[0] = 1;
    int idx = 1;
    int _parentNode = _parent[1];
    while(idx < n &&_parentNode != n){
        routes[idx] = _parentNode;
        _parentNode = _parent[_parentNode];
        idx++;
    }
    routes[idx] = n;
    if(n == 1) idx = 0;
    // output
    cout << execCount[1] << "\n";
    for (int i = 0; i < idx; i++){
        cout << routes[idx - i] << " ";
    }
    cout << routes[0];

	return 0;
}
