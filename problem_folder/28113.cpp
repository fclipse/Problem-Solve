#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
    fastio;
    int n, a, b;
    cin >> n >> a >> b;
    if(b < a){
        cout << "Subway";
    }else if(b > a){
        cout << "Bus";
    }else{
        cout << "Anything";
    }

    return 0; 
}