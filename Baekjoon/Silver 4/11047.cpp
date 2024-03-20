// Baekjoon No. 11047 동전 0 - 220825 solved.
// Time Complexity O(n)
// #Greedy
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, k, index, cnt;
    int i;
    scanf("%d %d", &n, &k);
    vector<int> coins(n, 0);
    for(i = 0; i < n; i++)
        scanf(" %d", &coins[i]);
    
    // solving
    /*
    1) 작은 수를 2개 이상 사용할 경우, 그 배수가 있다면 배수로 대체할 수 있다.
    2) 대체할 배수가 없는 경우는 그 경우가 최적해인 경우이다.
    큰 수가 안되면 그보다 작은 수를 사용할 때 작은 수에 1이 포함되기 때문에 무조건 해는 나옴.
    만약 작은수를 여러 개 조합해(2) 큰 수를 사용한 경우 (1)보다 더 최적인 경우가 있다고 가정하면,
    작은 수를 조합한 것을(2) 그 배수인 큰 수가 있다면(3) 그걸로 대체할 수 있고,
    없다면 그 경우(2)가 최적인 것임. 큰 수를 사용한 경우(1) 은 존재하지 않는 것.
    */
    cnt = 0;
    index = n - 1;
    while(index >= 0){
        if(k == 0)  // check해줘야 할 반례 케이스.
            break;
        if(k / coins[index] > 0){
            cnt += k / coins[index];
            k %= coins[index];
        }
        index --;
    }
    printf("%d", cnt);
    return 0;
}