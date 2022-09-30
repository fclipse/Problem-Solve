// Baekjoon No. 1005 ACM Craft 0 220829~ 220831
// Time Complexity O(nlogn)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k, w, check;
    int i, j, tc, tmp1, tmp2;
    scanf("%d", &t);

    for(tc = 0; tc < t; tc++){
        scanf(" %d %d", &n, &k);
        
        vector<int> time(n, 0);
        vector<int> memory(n, 0);  // 각 노드마다 짓는데 걸리는 시간 저장
        vector<int> order;
        queue<int> queue;
        vector<vector<int>> graph(n+1, vector<int>(n, 0));    // 마지막 n+1번째 열은 그 행 개수 합산한거 저장
        
        for(i = 0; i < n; i++)
            scanf(" %d", &time[i]);
        
        for(i = 0; i < k; i++){
            scanf(" %d %d", &tmp1, &tmp2);    // row -> col 형식. => col 에서의 합을 구해야 preBuild간선들 개수합 구할 수 있음.
            graph[tmp1-1][tmp2-1] = 1;
            graph[n][tmp2-1]++;
        }
        
        scanf(" %d", &w);
        // solving - 위상 정렬 이용, 순서 정해서 dp 사용하기
        // 순서 정하기
        for(i = 0; i < n; i++){
            if(!graph[n][i]){   // 연결된 간선 개수 == 0인 노드 추가
                queue.push(i);  // queue에는 노드번호 - 1 값이 저장됨.
            }
        }
        
        while(queue.size() > 0){
            check = queue.front();
            queue.pop();
            order.push_back(check); // queue에 있는 요소 하나 제거
            for(i = 0; i < n; i++){ // pop한 요소의 간선 모두 제거
                if(graph[check][i]){
                    graph[n][i]--;  // 원본 graph 연결 관계는 건들지 않고 연결된 개수만 -= 1
                    if(graph[n][i] == 0){    // 자신에게 연결된 간선이 모두 제거되었다면 큐에 추가
                        queue.push(i);  // 한 번만 추가해야 하므로 추가된건 음수로 넘김.
                        graph[n][i]--;
                    }
                }
            }
        }
        
        // dp 이용해 값 구하기
        // memory에는 각 idx의 노드마다 걸리는 시간 저장
        // 현재 노드 번호 -> order[i] + 1
        for(i = 0; i < n; i++){
            if(i == 0){ // 맨 처음 memory[0] 처리할 때
                memory[order[i]] = time[order[i]];
            }else{
                memory[order[i]] += time[order[i]];
                if(order[i] == w - 1)
                    break;
            }
            for (j = 0; j < n; j++) {
                if (graph[order[i]][j] && memory[j] < memory[order[i]]) {
                    memory[j] = memory[order[i]];
                }
            }
        }

        printf("%d\n", memory[w - 1]);
    }
    return 0;
}