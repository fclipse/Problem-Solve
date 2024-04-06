#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

using namespace std;

/**
 * @content
 * 문제
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 32,000), M(1 ≤ M ≤ 100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

출력
첫째 줄에 학생들을 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.
 * @brief
 * 주어진 data를 인접 리스트 방식으로 저장하여 위상정렬한 data를 출력하는 문제.
 * @return int
 */

int main()
{
    fastio;
    // input
    // n - number of students
    // m - number of pairs
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);   // input edge 차수
    vector<vector<int>> graph(n + 1); // 인접 리스트 방식으로 graph data저장
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        indegree[b]++;
    }

    // @debug
    // cout << ">> graph data\n";
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << i << " : ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // 1. input degree == 0인 노드 찾기
    queue<int> q; // 방문할 vertex 저장하는 queue
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i); // indegree == 0이면 queue에 push
        }
    }

    // 2. 위상 정렬 시행
    int currIdx = q.front();
    vector<int> answer; // 정답 순서 저장 list
    while (!q.empty())
    {
        // 1. 현재 idx 가져옴
        currIdx = q.front();
        q.pop();

        // 2. 해당 vertex의 모든 output edge제거 + target indegree 0이면 queue에 push
        for (int i = 0; i < graph[currIdx].size(); i++)
        {
            int targetIdx = graph[currIdx][i];
            indegree[targetIdx]--;
            if (indegree[targetIdx] == 0)
            {
                q.push(targetIdx);
            }
        }
        // 3. answer list에 해당 idx추가
        answer.emplace_back(currIdx);
    }

    // 3. output
    for (int v : answer)
    {
        cout << v << " ";
    }
    return 0;
}