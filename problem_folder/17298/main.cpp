#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;
// structs
typedef struct{
    int num, idx;
}Point;

// globals
int arr[SIZE] = {0};

int main() {
	fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // solving
    stack<Point> s;
    vector<int> nge(n, -1);
    for (int i = 0; i < n; i++){
        if(!s.empty()){
            while(!s.empty() && s.top().num < arr[i]){
                nge[s.top().idx] = arr[i];
                s.pop();
            }
        }
        s.push({arr[i], i});
    }

    // output
    for (int i = 0; i < n; i++){
        cout << nge[i] << " ";
    }
	return 0;
}