#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 64
using namespace std;

// struct
typedef struct{
    int x, y;
}Point;

// globals
int n;
bool arr[SIZE][SIZE] = {0};

// functions
string quadTree(Point st, Point ed);
bool isSame(Point st, Point ed);

int main() {
	fastio;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string str;
        getline(cin, str);
        for(int j = 0; j < n; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    // solving
    string result = quadTree({0, 0}, {n, n});

    // output
    cout << result;

	return 0;
}

// [st, ed) 까지의 범위 탐색
string quadTree(Point st, Point ed){
    Point mid = {(st.x +  ed.x) / 2, (st.y + ed.y) / 2};
    if(isSame(st, ed)) return arr[st.y][st.x] == 0 ? "0" : "1";

    string result;
    result += "(";
    result += quadTree(st, mid);
    result += quadTree({mid.x, st.y}, {ed.x, mid.y});
    result += quadTree({st.x, mid.y}, {mid.x, ed.y});
    result += quadTree(mid, ed);
    result += ")";
    return result;
}

bool isSame(Point st, Point ed){
    bool startPointValue = arr[st.y][st.x];
    for(int i = st.y; i < ed.y; i++){
        for(int j = st.x; j < ed.x; j++){
            if(arr[i][j] != startPointValue){
                return false;
            }
        }
    }
    return true;
}