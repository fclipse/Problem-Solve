// Baekjoon No. 25304 - ¿µ¼öÁõ, 220811 solved
// Time Complexity O(n)
#include <iostream>
using namespace std;
int main(){
    int x, n, cost, num, i, j;
    scanf("%d %d", &x, &n);
    for(i = 0; i < n; i++){
        scanf(" %d %d", &cost, &num);
        x -= cost * num;
    }
    if(x == 0)
        printf("Yes");
    else
        printf("No");
    return 0;
}