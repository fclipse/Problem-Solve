#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000001
using namespace std;
// 240515 solved, 오큰수 참고
// struct
typedef struct{
    int num, idx;
}Point;

int counter[SIZE] = {0};

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // solving
    stack<Point> s;
    vector<int> ngf(n, -1);
    for (int i = 0; i < n; i++){
        counter[arr[i]]++;
    }
    for (int i = 0; i < n; i++){
        if(!s.empty()){
            while(!s.empty() && counter[s.top().num] < counter[arr[i]]){
                ngf[s.top().idx] = arr[i];
                s.pop();
            }
        }
        s.push({arr[i], i});
    }
    

    // output
    for (int i = 0; i < n; i++){
        cout << ngf[i] << " ";
    }
    
	return 0;
}