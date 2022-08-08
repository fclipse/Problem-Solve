#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    // 조합 구현 stl 예제
    int n, cnt = 0;
    scanf("%d", &n);
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        arr[i] = (i < n/2) ? 0 : 1;
    }

    do{
        for(int i = 0; i < n; i++){
            printf("%2d ", arr[i]);
        }
        printf("\n");
        cnt++;
    }while(next_permutation(arr.begin(), arr.end()));
    printf("cnt : %d", cnt);
    return 0;
}