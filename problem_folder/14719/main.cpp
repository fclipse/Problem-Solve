#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define SIZE 500
using namespace std;

int heights[SIZE] = {0};

int main() {
	fastio;
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < w; i++){
        cin >> heights[i];
    }
    // solving
    int ans = 0;
    int baseHeight = heights[0];
    int baseIdx = 0;
    for (int i = 1; i < w; i++){
        int delta = baseHeight - heights[i];
        // cout << "i - " << i << " | ";
        if(delta > 0){
            ans += delta;
            // cout << "+ " << delta << endl;
            // cout << "ans: " << ans << endl;
        }else{
            baseHeight = heights[i];
            baseIdx = i;
            // cout << "baseHeight: " << baseHeight << " / " << "baseIdx: " << baseIdx << endl;
        }
        // 마지막에 물이 넘칠때 넘치는 양만큼 다시 빼줌
        if(i == w - 1 && delta > 0){
            int newBaseHeight = heights[i];
            int newBaseIdx = i;
            // 끝에서부터 다시 가면서 계산.
            for (int st = i; st >= baseIdx + 1; st--){
                // 기존 추가했던 기록 빼줌
                ans -= baseHeight - heights[st];
                // 만약 물이 고일 수 있다면
                if(heights[st] < newBaseHeight) {
                    ans += newBaseHeight - heights[st];
                }else{
                    // heights[i]보다 큰게 나오면 다시 기준점을 잡음
                    newBaseHeight = heights[st];
                    newBaseIdx = st;
                }
            }
        }
    }
    
    // output
    cout << ans;
    
	return 0;
}