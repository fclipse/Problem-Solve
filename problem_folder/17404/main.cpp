#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
#define INF 1000001
using namespace std;

/**
 * R = 0, G = 1, B = 2로 취급
 */
int cost[SIZE][3] = {0};
int result[SIZE][3] = {0};
int firstSelectedNum[SIZE][3] = {0};

// functions
int mod_3(int n);
int getLeftNum(int n1, int n2);

int main() {
	fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            cin >> cost[i][j];
        }
    }
    // solving
    int ans = INF;
    for (int i = 0; i < 3; i++){
        result[0][i] = cost[0][i];
        firstSelectedNum[0][i] = i;
    }
    
    for (int i = 1; i < n - 1; i++){
        for (int j = 0; j < 3; j++){
            if(result[i - 1][mod_3(j - 1)] >= result[i - 1][mod_3(j + 1)]){
                result[i][j] = result[i - 1][mod_3(j - 1)] + cost[i][j];
                firstSelectedNum[i][j] = firstSelectedNum[i - 1][mod_3(j - 1)];
            }else{
                result[i][j] = result[i - 1][mod_3(j + 1)] + cost[i][j];
                firstSelectedNum[i][j] = firstSelectedNum[i - 1][mod_3(j + 1)];
            }
        }
    }
    for (int i = 0; i < 3; i++){
        for(int prev = 0; prev < 3; prev++){
            if(prev == i) continue;
            int firstSelected = firstSelectedNum[n - 2][prev];
            if(firstSelected == i) continue;
            if(result[n - 1][i] == 0) result[n - 1][i] = result[n - 2][prev] + cost[n - 1][i];
            else result[n - 1][i] = min(result[n - 1][i], result[n - 2][prev] + cost[n - 1][i]);
        }
    }
    /*
    cout << "result" << endl;
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < n; i++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
        
    for (int i = 0; i < 3; i++){
        if(result[n - 1][i] != 0) ans = min(ans, result[n - 1][i]);
    }

    cout << ans;
	return 0;
}

// n % 3의 결과를 양수로 출력
int mod_3(int n){
    if(n < 0) return (n + 3) % 3;
    return n % 3;
}

// 3개 숫자중 남은 수를 반환하는 함수
int getLeftNum(int n1, int n2){
    if(n1 == n2) return -1;
    return 6 - (n1 + n2);
}