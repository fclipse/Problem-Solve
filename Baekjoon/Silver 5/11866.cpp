// Baekjoon No. 11866 요세푸스 문제 0 - solved 220815
// Time Complexity O(n*k) ... 최약 O(n^2)인데 됨...
// n명의 사람들 있을때 n번 돌아가면서 k번째 사람 고르고, 제거하기를 반복.
// 그렇게 나온 수열 출력하는 문제.
// linked list array로 구현해서 해결
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k, ptr, nextIdx, prevIdx;
    int i, j, index = 0;
    scanf("%d %d", &n, &k);
    vector<vector<int>> linkedLst(n, vector<int>(2, 0));
    vector<int> seq(n, 0);
    // init
    linkedLst[0][0] = n - 1;    // 이전 idx
    linkedLst[0][1] = 1;        // 이후 idx
    for(i = 1; i < n-1; i++){
        linkedLst[i][0] = i - 1;
        linkedLst[i][1] = i + 1;
    }
    linkedLst[n-1][0] = (n - 2) % n;    // 1 1 입력받을때 [[0, 0]]으로 설정되어야 함.
    linkedLst[n-1][1] = 0;
    
    // solve
    ptr = 0;
    index = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < k-1; j++)
            ptr = linkedLst[ptr][1];
        // 삭제할 idx -> ptr
        seq[index] = ptr + 1;
        index++;
        nextIdx = linkedLst[ptr][1];
        prevIdx = linkedLst[ptr][0];
        
        
        // 삭제할 노드 이전 노드의 nextIdx값을 다음 노드가 가리키는 idx로 바꿔줌
        linkedLst[prevIdx][1] = nextIdx;
        linkedLst[nextIdx][0] = prevIdx;
        ptr = nextIdx;
    }
    // output
    printf("<");
    for(i = 0; i < n - 1; i++)
        printf("%d, ", seq[i]);
    printf("%d>", seq[n-1]);
    return 0;
}