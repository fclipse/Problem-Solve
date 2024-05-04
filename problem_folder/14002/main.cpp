#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
using namespace std;

// 240430 solved

// global
int arr[SIZE] = {0};
int ans[SIZE] = {0};
int position[SIZE] = {0};

int main() {
	fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // solving
    // 1로 init
    int maxLength = 1;
    for (int i = 0; i < n; i++){
        position[i] = 1;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if(arr[i] > arr[j] && position[j] + 1 > position[i]){
                position[i] = position[j] + 1;
                maxLength = max(maxLength, position[i]);
            }
        }
    }
    int idx = 0;
    int target = maxLength;
    for (int i = 0; i < n; i++){
        if(target == 0) break;
        idx = n - 1 - i;
        if(position[idx] == target){
            ans[target - 1] = arr[idx];
            target--;
        }
    }

    // output
    cout <<maxLength << "\n";
    for (int i = 0; i < maxLength; i++){
        cout << ans[i] << " ";
    }
	return 0;
}