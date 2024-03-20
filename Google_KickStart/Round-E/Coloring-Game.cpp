#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t, n, maxScore = 0, left_num;
    int i, j;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf(" %d", &n);
        left_num = n;
        maxScore = 0;
        
        // solving
        while(left_num > 0){
            left_num -= 2;  // bot
            maxScore += 1;

            left_num -= 3;
        }
        
        // output
        printf("Case #%d: %d\n", i+1, maxScore);
    }
    return 0;
}
// 5개일때 John이 bot의 개수를 최소로 만들려면 한 번에 3칸씩 제거 가능하다는걸 알았음.
// 공식화시킬수도 있지만 통과했으니 ㄱㅊ
// 1 0 0 2 0 1
// 1 0 0 2 0
// 1 0 2 0