# RGB거리 2

- 백준 17404
- <https://www.acmicpc.net/problem/17404>
- 240429~

## 생각

1. DP를 이용한 풀이 - O(N)
    - 아이디아: 첫 번째 집이랑 두 번째 집, n번째 집만 따로 조건을 걸고, 나머지는 앞의 두 개의 집을 보고 비용을 결정.
2. 어차피 0, 1, n - 1번째만 정하면, 그 가운데는 알아서 정해지는거 아닌가?

- 이렇게 해서 3! = 6가지 경우만 계산하면 안되나?
-> 이건 안함..

## test cas

3
26 40 83
49 60 57
13 89 99

2
1 1 1
1 1 1

2
1 1 1
1 2 2

3
1 1 1
1 1000 1000
1000 1 1000

## 1. 초기 코드

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            if(i == 0){
                result[i][j][0] = cost[i][j];
                result[i][j][1] = cost[i][j];
            }else if(i == 1){
                result[i][j][0] = result[i - 1][mod_3(j - 1)][0]  + cost[i][j];
                result[i][j][1] = result[i - 1][mod_3(j + 1)][1]  + cost[i][j];

            }else if(i == n - 1){
                result[i][j][0] = result[i - 1][mod_3(j - 1)][0] + result[0][mod_3(j + 1)][0] + cost[i][j];
                result[i][j][1] = result[i - 1][mod_3(j + 1)][1] + result[0][mod_3(j - 1)][1] + cost[i][j];
            }else{
                result[i][j][0] = result[i - 1][mod_3(j - 1)][0] + result[i - 2][mod_3(j + 1)][0] + cost[i][j];
                result[i][j][1] = result[i - 1][mod_3(j + 1)][1] + result[i - 2][mod_3(j - 1)][1] + cost[i][j];
            }
        }
    }
    cout << "cost" << endl;
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < n; i++){
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "result" << endl;
    for(int k = 0; k < 2; k++){
        cout << "k : " << k << endl;
        for (int j = 0; j < 3; j++){
            for (int i = 0; i < n; i++){
                cout << result[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

    ans = result[n - 1][0][0];
    for (int k = 0; k < 2; k++){
        for (int i = 0; i < 3; i++){
            ans = min(ans, result[n - 1][i][k]);
        }

    }
