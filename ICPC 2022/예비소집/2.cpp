// Baekjoon No.
// Time Complexity
// #

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, resCnt, res;
    int i, j;
    // saves sum
    cin >> m >> n;
    vector<vector<int>> ground(m, vector<int>(n, 0));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> ground[i][j];
            if (j != 0) {
                ground[i][j] += ground[i][j - 1];
            }
            if (i != 0) {
                ground[i][j] += ground[i - 1][j];
            }
        }
    }

    // solving
    resCnt = 0;
    for (int y1 = 0; y1 < m; y1++) {
        for (int x1 = 0; x1 < n; x1++) {
            for (int y2 = y1; y2 < m; y2++) {
                for (int x2 = x1; x2 < n; x2++) {
                    if (x2 == x1 && y2 == y1) {
                        if (ground[y1][x1] == 10) {
                            resCnt++;
                            break;
                        }
                        else if (ground[y1][x1] > 10) {
                            break;
                        }
                    }
                    else if(x1 == x2) {
                        if (ground[y1][x1] - ground[y1][x2] - ground[y2][x1] + ground[y2][x2] == 10) {
                            resCnt++;
                            break;
                        }
                        else if (ground[y1][x1] - ground[y1][x2] - ground[y2][x1] + ground[y2][x2] > 10) {
                            break;
                        }
                    }
                    else if(y1 == y2) {
                        if (ground[y1][x1] - ground[y1][x2] - ground[y2][x1] + ground[y2][x2] == 10) {
                            resCnt++;
                            break;
                        }
                        else if (ground[y1][x1] - ground[y1][x2] - ground[y2][x1] + ground[y2][x2] > 10) {
                            break;
                        }
                    }
                    else{
                        if (ground[y1][x1] - ground[y1][x2] - ground[y2][x1] + ground[y2][x2] == 10) {
                            resCnt++;
                            break;
                        }
                        else if (ground[y1][x1] - ground[y1][x2] - ground[y2][x1] + ground[y2][x2] > 10) {
                            break;
                        }
                    }
                    
                }
            }
        }
    }
    cout << resCnt;

    return 0;
}