// Baekjoon No. 7863 - Very Simple Problem / 0810 solved.
// n * p 입력을 받은 배열 중 각 행에서 가장 작은 인덱스를 각각 선택할 때,
// 과반수 이상의 행의 선택을 받은 인덱스+1을 오름차순으로 출력하는 문제
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, p, minIdx, hrdIdx, cnt = 0;
    int i, j;
    scanf("%d %d", &n, &p);
    vector<vector<int>> ratings(n, vector<int>(p, 0));
    vector<int> simpleNumbers(p, 0);    // 각자가 생각하는 simplest idx 저장
    
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            scanf(" %d", &ratings[i][j]);
        }
    }

    // solving
    for(i = 0; i < n; i++){
        minIdx = 0;
        hrdIdx = 0;
        // 각자의 simplest idx 찾음
        for(j = 1; j < p; j++){
            if(ratings[i][j] < ratings[i][minIdx]){
                minIdx = j;
            }
            if(ratings[i][j] > ratings[i][hrdIdx]){
                hrdIdx = j;
            }
        }
        // minIdx 값과 같은것들 전부 ++시킴
        for(j = 0; j < p; j++){
            if(ratings[i][j] == ratings[i][minIdx]){
                simpleNumbers[j] ++;
            }
            if(ratings[i][j] == ratings[i][hrdIdx]){
                simpleNumbers[j] -= n;  // ** point hardest 하나라도 있으면 고를 수 없도록 함.
            }
        }
            
    }

    for(i = 0; i < n; i++){
        if(simpleNumbers[i] > n/2.0){
            printf("%d ", i+1);
            cnt++;
        }
    }
    if(!cnt)    // very simple 하나도 없을시 0 출력
        printf("0");
    return 0;
}