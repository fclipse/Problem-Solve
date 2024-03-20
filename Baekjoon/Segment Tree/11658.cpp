#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1024
using namespace std;

int board[SIZE][SIZE];
int segTree[SIZE][SIZE * 4];

int init(int nodeIdx, int y, int st, int ed);
int modify(int nodeIdx, int y, int st, int ed, int x, int c);
int query(int nodeIdx, int y, int st, int ed, int l, int r);

int main(){
    fastIO
    int n, m, w, x1, y1, x2, y2, sum, c;
    int i, j;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    // solving
    for(i = 0; i < n; i++){
        init(1, i, 1, n);
    }

    for(i = 0; i < m; i++){
        cin >> w;
        if(w){
            cin >> x1 >> y1 >> x2 >> y2;
            sum = 0;
            for(j = x1; j <= x2; j++){
                sum += query(1, j-1, y1, y2, 1, n);
            }
            cout << sum;
        }else{
            cin >> x1 >> y1 >> c;
            modify(1, x1 - 1, 1, n, y1, c);
        }
    }
    return 0;
}
int init(int nodeIdx, int y, int st, int ed){
    if(st == ed) return segTree[y][nodeIdx] = board[y][st - 1];
    int mid = (st + ed) / 2;
    return segTree[y][nodeIdx] = init(nodeIdx * 2, y, st, mid) + init(nodeIdx * 2 + 1, y, mid + 1, ed);
}
int modify(int nodeIdx, int y, int st, int ed, int x, int c){
    int tmp, mid = (st + ed) / 2;
    if(st == ed){
        tmp = segTree[y][nodeIdx];
        segTree[y][nodeIdx] = c;
    }else{
        if(mid < x) tmp = modify(nodeIdx * 2 + 1, y, mid + 1, ed, x, c);
        else tmp = modify(nodeIdx * 2, y, st, mid, x, c);
        segTree[y][nodeIdx] += c - tmp;
    }
    return tmp;
}
int query(int nodeIdx, int y, int st, int ed, int l, int r){
    if(l <= st && ed <= r) return segTree[y][nodeIdx];
    if(ed < l || r < st) return 0;
    int mid = (st + ed) / 2;
    return query(nodeIdx * 2, y, st, mid, l, r) + query(nodeIdx * 2 + 1, y, mid + 1, ed, l, r);
}