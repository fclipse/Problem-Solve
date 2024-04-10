#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1000000

using namespace std;

// globals
int arr[MAX] = {0};

// functions
int binSearch(int st, int ed);

int main() {
	fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int p1 = 0, p2 = n - 1;
    sort(arr, arr + n);
    p1 = binSearch(0, n - 1);


    // output

	return 0;
}

// 0과 가까운 가장 작은 수의 위치를 찾는 이진탐색
int binSearch(int st, int ed){
    int mid = (st + ed) / 2;
}
