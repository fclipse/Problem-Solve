#include <stdio.h>
#include <time.h>

// 함수 선언
void n_queen(int i, int j);
int check(int i, int j);

// 전역 변수 설정
int cnt = 0;
int n = 0;
int board[15][15] = {0, };
int queens = 0;

int main(void){
    double start, end;
    scanf("%d", &n);

    start = (double)clock() / CLOCKS_PER_SEC;   // 시작시간
    n_queen(0, 0);
    end = (double)clock() / CLOCKS_PER_SEC;     // 종료시간
    printf("%d\n", cnt);
    printf("time : %.4lf\n", end - start);
    return 0;
}

int check(int i, int j){
    // 가로세로
    for(int k = 0; k < n; k++){
        if(board[k][j] != 0 || board[i][k] != 0)
            return 0;
    }

    // 오른쪽 아래
    if(i - j >= 0){
        for(int k = 0; k < n - (i - j); k++){
            if(board[i - j + k][k] != 0){
                if(k != j)
                    return 0;
            }
        }
    }
    else{
        for(int k = 0; k < n - (j - i); k++){
            if(board[k][j - i + k] != 0){
                if(k != i)
                    return 0;
            }
        }
    }

    // 왼쪽 아래로
    if(i + j <= n-1){
        for(int k = 0; k < i + j + 1; k++){
            if(board[k][i + j - k] != 0){
                if(i != k)
                    return 0;
            }
        }
    }
    else{
        for(int k = 0; k < 2*n - 1 - (i + j); k++){
            if(board[i + j - n + 1 + k][n - 1 - k] != 0){
                if(n - 1 - k != j)
                    return 0;
            }
        }
    }

    return 1;
}

void n_queen(int i, int j){
    int next_i = 0;
    int next_j = 0;

    for(int k = 0; k < n*n; k++){
        if((i*n + j + k) == n*n)
            return;
        if(check((i*n+j+k) / n, (j+k)%n) == 1 && board[(i*n+j+k) / n][(j+k)%n] == 0){
            board[(i*n+j+k) / n][(j+k)%n] = 2;
            queens++;

            if(queens == n){    // 완성되었을 때
                cnt++;
                queens--;
                board[(i*n+j+k) / n][(j+k)%n] = 0;
                continue;
            }

            next_j = (j+k) % n + 1;
            next_i = (n*i + j + k) / n;
            if(next_j == n){
                next_i++;
                next_j = 0;
            }
            if(next_i == n){
                board[n-1][n-1] = 0;
                queens--;
                return;
            }

            n_queen(next_i, next_j);
            queens--;
            board[(i*n+j+k) / n][(j+k)%n] = 0;
        }
    }
    return;
}