// Baekjoon No. 20173 Imprecise Computer - 220916~
// Time Complexity
// #

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, success = 1;
    int i;
    cin >> n;
    vector<int> d(n);
    vector<map<int, int>> memory(n, map<int, int>{ {0, 0}, { 1, 0 }, { 2, 0 }});
    for (i = 0; i < n; i++)
        cin >> d[i];

    // solve
    // i == 0 은 먼저 처리해줌

    i = 1;
    while(success && i < n) {
        // 여기 if문에서 확인해줌, memory[i] 안에 d[i]값이 있으면서 그 값이 들어올 수 있는 상태일 때
        if (memory[i].find(d[i]) != memory[i].end() && memory[i][d[i]]) {
            // 마지막 번호가 아니라면 다음 번호에 들어갈 수 있는 숫자 추가해줌
            if (i < n - 2) {
                switch (d[i]) {
                case 0:
                    memory[i + 1][1] = 1;
                    memory[i + 1][2] = 1;
                    break;
                case 1:
                    memory[i + 1][1] = 1;
                    if (d[i - 1] == 0)
                        memory[i + 1][2] = 1;
                    else
                        memory[i + 1][0] = 1;
                    break;
                case 2:
                    memory[i + 1][0] = 1;
                    memory[i + 1][1] = 1;
                    break;
                default:
                    success = 0;
                    break;
                }
            }
            else if (i == n - 2) {
                switch (d[i]) {
                case 0:
                    memory[i + 1][1] = 1;
                    break;
                case 1:
                    if (d[i - 1] == 0)
                        memory[i + 1][1] = 1;
                    else
                        memory[i + 1][0] = 1;
                    break;
                case 2:
                    memory[i + 1][0] = 1;
                    break;
                default:
                    success = 0;
                    break;
                }
            }
        }
        else {
            success = 0;
        }
        i++;
    }
        

    // output
    if (success)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}