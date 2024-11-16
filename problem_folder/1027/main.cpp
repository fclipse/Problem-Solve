#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 50
#define MAX 1000000000
using namespace std;

// globals
int n;
int heights[SIZE] = {0};

int main() {
	fastio;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> heights[i];
    }
    // solving
    int ans = 0;
    for (int idx = 0; idx < n; idx++){
        int cnt = 0;
        int maxDx, maxDy;   // 최대인 기울기를 dx, dy로 나눠서 저장 (정수 범위 유지)
        if(idx > 0){
            maxDx = -1;
            maxDy = heights[idx - 1] - heights[idx];
            cnt++;
        }
        // 왼쪽 개수 셈
        for (int leftIdx = idx - 2; leftIdx >= 0; leftIdx--){
            int dx = leftIdx - idx;
            int dy = heights[leftIdx] - heights[idx];
            if((long long)maxDx * dy < (long long)maxDy * dx){
                // 빌딩이 보일 때 - 기울기가 더 작을 때 (왼쪽 방향이므로)
                cnt++;
                maxDx = dx;
                maxDy = dy;
            }
            if(heights[leftIdx] == MAX) {
                // 높이가 최대인게 나오면 그 이후로는 전부 안보이므로 pass 
                break;
            }
        }
        
        // 오른쪽 개수 셈
        if(idx < n - 1){
            maxDx = 1;
            maxDy = heights[idx + 1] - heights[idx];
            cnt++;
        }
        for (int rightIdx = idx + 2; rightIdx < n; rightIdx++){
            int dx = rightIdx - idx;
            int dy = heights[rightIdx] - heights[idx];
            if((long long)maxDx * dy > (long long)maxDy * dx){
                // 빌딩이 보일 때 - 기울기가 더 클 때
                cnt++;
                maxDx = dx;
                maxDy = dy;
            }
            if(heights[rightIdx] == MAX) {
                // 높이가 최대인게 나오면 그 이후로는 전부 안보이므로 pass 
                break;
            }

        }
        // cout << "idx - " << idx << " cnt - " << cnt << endl;
        // ans 업데이트
        ans = max(ans, cnt);
    }
    

    // output
    cout << ans;

	return 0;
}