#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 2000000000
using namespace std;

// functions
int binSearch(int, int, int, vector<int>&);

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> inputArray(n);
    vector<int> lis(n + 1, MAX);
    for(int i = 0; i < n; i++){
        cin >> inputArray[i];
    }

    // solving - 이진탐색으로 들어갈 인덱스를 찾은 다음, 인덱스가 있으면 해당 인덱스에 값 집어넣음
    // O(NlgN)
    for(int i = 0; i < n; i++){
        int idx = binSearch(inputArray[i], 1, n, lis);
        if(idx > 0){
            lis[idx] = inputArray[i];
        }
    }

    // output - 배열에서 MAX보다 작지만 가장 큰 값 출력; O(N)
    int answer = 0;
    for(int i = 0; i <= n; i++){
        if(lis[i] < MAX){
            answer = i;
        }
    }
    cout << answer;
	return 0;
}

/**
 * 이진 탐색 알고리즘 - 재귀 사용
 * target : 주어진 범위 내 수들 중 가장 큰 수들 중 가장 작은 수의 위치
 * 배열은 정렬되어있는 상태임
 * 만약 배열의 모든 값이 
 * 1. 만약 배열의 맨 작은 값이 비굣값(baseValue)보다 크면 st 반환 -> 배열의 모든 값이 비굣값보다 큰 경우임
 * 2. 만약 배열의 가장 큰 값이 비굣값보다 작거나 같으면 -1 반환 -> 배열의 모든 값이 비굣값보다 작거나 같은 경우임
 * (if문 안에서)
 * 3. 만약 pivot이랑 동일하면 -1 return (이미 lis에는 해당 값이 반영된 상태 - 더 이상 비교는 불필요)
 * 4. 만약 pivot보다 크면 mid + 1 이후의 값들 대상으로 다시 비교
 * 5. 만약 pivot보다 작다면 mid 포함 이전의 값들 대상으로 다시 비교
*/
int binSearch(int baseValue, int st, int ed, vector<int>& arr){
    // 값이 똑같아도 여기서 걸러줌
    if(arr[st] > baseValue) return st;  // 배열에서 가장 작은 값이 baseValue보다 큰 경우 -> 답은 st임
    if(arr[ed] <= baseValue) return -1;  // 배열에서 가장 큰 값이 baseValue보다 작은 경우 -> baseValue보다 작은 값 없음, -1 return
    
    int mid = (st + ed) / 2;
    int pivot = arr[mid];
    if(pivot == baseValue) return -1;   // 이미 해당 값이 lis에 있다면, 추가할 필요가 없음
    else if(pivot < baseValue) return binSearch(baseValue, mid+1, ed, arr);
    else return binSearch(baseValue, st, mid, arr);
}