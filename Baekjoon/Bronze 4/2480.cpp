#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int arr[3] = {0};
    int dice[6] = {0};
    int i, ans = 0;
    for(i = 0; i < 3; i++){
        scanf(" %d", &arr[i]);
    }

    //solving
    if(arr[0] == arr[1] && arr[1] == arr[2])    // 모두 같을 경우
        ans = 10000 + arr[0] * 1000;
    else if(arr[0] != arr[1] && arr[1] != arr[2] && arr[2] != arr[0])   // 모두 다를 경우
        ans = max(max(arr[0], arr[1]), arr[2]) * 100;
    else{    // 두개만 같을 경우
        for(i = 0; i < 3; i++){
            dice[arr[i]-1]++;
        }
        for(i = 0; i < 6; i++){
            if(dice[i] == 2)
                ans = 1000 + (i+1) * 100;
        }
    }
    printf("%d", ans);
    return 0;
}