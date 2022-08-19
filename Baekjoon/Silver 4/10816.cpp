// Baekjoon No. 10816 카드 번호 - 220815 solved
// Time Complexity O(n)
// Solved.ac # Class 1
// n개의 카드 번호를 받고, m개의 입력에서 각각 그 카드 번호가 몇 개 존재하는지 출력하는 프로그램
// map자료형 사용해 문제 해결. -> O(n) 만에 해결가능.
// array 사용했다면 TC = O(m * n) 걸려서 어려울거라 생각.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, m, tmp;
    int i;
    scanf("%d", &n);
    map<int, int> cards;
    for(i = 0; i < n; i++){
        scanf(" %d", &tmp);
        if(cards.find(tmp) == cards.end())  // 존재하지 않을 때
            cards[tmp] = 1;
        else    // key값 존재할 때
            cards[tmp]++;
    }
    
    scanf(" %d", &m);
    for(i = 0; i < m; i++){
        scanf(" %d", &tmp);
        printf("%d ", cards[tmp]);
    }   

    return 0;
}