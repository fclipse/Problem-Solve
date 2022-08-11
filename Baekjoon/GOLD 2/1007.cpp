#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// swap하고자 하는 arr주소, 인덱스1, 인덱스2
void swapArr(int (*vectors)[2], int, int);

int main(){
    ios::sync_with_stdio(false);
    int n, m, t, i, j, k, l;
    int sx, sy;
    double result, maxSum = 0;
    int vectors[20][2] = {0};
    scanf("%d", &t);

    // 각 test case마다
    for(i = 0; i < t; i++){
        sx = 0;
        sy = 0;
        result = 0;
        maxSum = 0;
        scanf(" %d", &n);
        m = n / 2;  // m == n/2
        vector<int>combination(n);
        // combination -> 0부터 n-1까지 오름차순으로 집어넣음.
        for(int j = 0; j < n; j++)
            combination[j] = (j < m) ? 0 : 1;
        
        for(j = 0; j < n; j++)
            scanf(" %d %d", &vectors[j][0], &vectors[j][1]);

        // printf("coords:\n");
        // for(j = 0; j < n; j++){
        //     for(k = 0; k < 2; k++){
        //         printf("%d ", vectors[j][k]);
        //     }
        //     printf("\n");
        // }
        // nCm 조합 구현, m == n / 2
        do{
            for(j = 0; j < n; j++){
                sx = (combination[j]) ? sx + vectors[j][0] : sx - vectors[j][0];
                sy = (combination[j]) ? sy + vectors[j][1] : sy - vectors[j][1];
            }
            result = sqrt(pow(sx, 2) + pow(sy, 2));
            maxSum = (maxSum < result) ? result : maxSum;
        }while(next_permutation(combination.begin(), combination.end()));
        printf("%d\n", maxSum);
    }
    return 0;
}

void swapArr(int (*vectors)[2], int i, int j){
    int tmpArr[2] = {0};
    tmpArr[0] = vectors[i][0];
    tmpArr[1] = vectors[i][1];
    
    vectors[i][0] = vectors[j][0];
    vectors[i][1] = vectors[j][1];

    vectors[j][0] = tmpArr[0];
    vectors[j][1] = tmpArr[1];
    return;
}