// Baekjoon No. 2156 포도주 시식 220801~
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, i, j;
    scanf("%d", &n);
    vector<int>wines(n, 0);
    vector<int>arr(n, 0);
    for(i = 0; i < n; i++)
        scanf(" %d", &wines[i]);
    
    // 초깃값만 각각 설정
    arr[0] = wines[0];
    if(n > 1)
        arr[1] = wines[0] + wines[1];
    if(n > 2)
        arr[2] = max(wines[0], wines[1]) + wines[2];
    for(i = 3; i < n; i++){
        arr[i] = max(max(arr[i-3] + wines[i-1] + wines[i], arr[i-2] + wines[i]), arr[i-1]);
    }

    if(n > 1)
        printf("%d", arr[n-1]);  // 마지막에 arr[i-3], arr[i-2]만 확인하고 arr[i-1]은 확인 안하므로 맨 마지막이 최대라는 보장 x
    else
        printf("%d", arr[0]);   // index 에러 방지
    return 0;
}
// 100 200 101 201 