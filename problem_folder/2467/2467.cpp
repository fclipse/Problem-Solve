#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LEN 1000000
#define MAX 2000000000

using namespace std;

// globals
int arr[LEN] = {0};

int main() {
	fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int p1 = 0, p2 = n - 1;
    pair<int, int> answerPair;
    int minSum = MAX;   // 어떤 두 수의 합이라도 20억 미만이 확실 -> 무조건 한 번은 초기화됨

    sort(arr, arr + n);
    while(p1 < p2){
        int sum = arr[p1] + arr[p2];
        if(minSum > abs(sum)){
            minSum = abs(sum);
            answerPair.first = arr[p1];
            answerPair.second = arr[p2];
        }
        
        if(sum == 0) break;
        else if(sum > 0) p2--;
        else p1++;
    }

    // output
    cout << answerPair.first << " " << answerPair.second;
	return 0;
}