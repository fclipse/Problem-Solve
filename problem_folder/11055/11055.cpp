#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lis(n, 0);  // 첫 번째 행에는 lis 정보 저장, 두 번째 행에는 sum 정보 저장
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    for(int i = 0; i < n; i++){
        // arr에 있는 각 수들 대상으로 for 문 진행
        lis[i] = arr[i];
        for(int j = 0; j <= i; j++){
            // 0~i까지의 arr에 있는 수들 중 작은 수들 대상으로 lis[i]값 업데이트
            if(arr[j] < arr[i]){
                lis[i] = max(lis[i], lis[j] + arr[i]);
            }
        }
    }

    // output - sum중 가장 큰 값 출력; O(N)
    int ans = lis[0];
    for(int i = 1; i < n; i++){
        ans = max(ans, lis[i]);
    }
    cout << ans;

	return 0;
}