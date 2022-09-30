// Baekjoon No. 10026 적록색약
// Time Complexity
#include <iostream>
using namespace std;

void dfs(int x, int y, int** visited, char** board, int n);
void gr_dfs(int x, int y, int** visited, char** board, int n);
int main(){
    ios::sync_with_stdio(false);
    int n, area_cnt = 0, gr_area_cnt = 0;
    int i, j;
    char board[100][100];
    int visited[100][100] = {0};
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf(" %c", &board[i][j]);
        }
    }
    
    // solving
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(!visited[i][j]){

            }
        }
    }
    return 0;
}

void dfs(int x, int y, int** visited, char** board, int n){
    char type = board[y][x];
    visited[y][x] = 1;
    if(y > 0 && board[y-1][x] == type && !visited[y][x])
        dfs(x, y-1, visited, board, n);
    if(x > 0 && board[y][x-1] == type)
        dfs(x-1, y, visited, board, n);
    if(y < n-1 && board[y+1][x] == type)
        dfs(x, y+1, visited, board, n);
    if(x < n-1 && board[y][x+1] == type)
        dfs(x+1, y, visited, board, n);
    return;
}

void gr_dfs(int x, int y, int** visited, char** board, int n){
    char type = board[y][x];
    // Blue인지만 판정.
    
    visited[y][x] = 1;
    if(y > 0 && board[y-1][x] == type)
        dfs(x, y-1, visited, board, n);
    if(x > 0 && board[y][x-1] == type)
        dfs(x-1, y, visited, board, n);
    if(y < n-1 && board[y+1][x] == type)
        dfs(x, y+1, visited, board, n);
    if(x < n-1 && board[y][x+1] == type)
        dfs(x+1, y, visited, board, n);
    return;
}