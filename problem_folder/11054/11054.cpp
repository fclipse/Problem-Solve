#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    // 증가 - 1 / 감소 - -1
    vector<vector<int>> lis(2, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int maxLength = 1;
    for(int i = 0; i < n; i++){
        lis[0][i] = 1;  // 증가중일때의 기본 lis 길이
        lis[1][i] = 1;  // 감소중일때의 기본 lis 길이
        for(int j = 0; j < i; j++){
            // 증가 lis 작성
            if(arr[j] < arr[i] && lis[0][j] >= lis[0][i]){
                lis[0][i] = lis[0][j] + 1;
            }
            // 감소 lis 작성
            if(arr[j] > arr[i]){
                // 감소 lis 작성 - 감소 부분 참고
                if(lis[1][j] >= lis[1][i]){
                    lis[1][i] = lis[1][j] + 1;
                }
                // 감소 lis 작성 - 증가 부분 참고
                if(lis[0][j] >= lis[1][i]){
                    lis[1][i] = lis[0][j] + 1;
                }
            }
            maxLength = max(maxLength, max(lis[0][i], lis[1][i]));
        }
    }

    // output
    cout << maxLength;
	return 0;
}