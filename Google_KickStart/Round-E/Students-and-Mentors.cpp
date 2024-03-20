#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, t, maxNum, duo, tmp;
    int tc, i;
    scanf("%d", &t);
    for(tc = 0; tc < t; tc++){
        scanf(" %d", &n);
        vector<int> students(n, 0);
        vector<int> mentors(n, 0);
        vector<int> temp;
        priority_queue<int> m;
        for(i = 0; i < n; i++){
            scanf(" %d", &students[i]);
            m.push(students[i]);
        }
        
        // solving
        // 가장 큰 수가 2개 겹칠 때는 서로 멘토가 될 수 있음.
        // 우선순위 큐 이용해서 문제 해결하려 했는데 자기 자신을 멘토로 가지는 경우를 아직 해결하지 못함.
        maxNum = m.top();
        m.pop();
        if(maxNum == m.top())
            duo = 1;
        else
            duo = 0;
        m.push(maxNum);
        
        for(i = 0; i < n; i++){
            // 조건에 맞지 않는 것들은 계속 temp로 빼냄 
            while(m.size() > 0 && m.top() > students[i] * 2){
                // printf("compare: %d %d\n", m.top(), students[i]);
                temp.push_back(m.top());
                m.pop();
            }
            // 큐에 남아있는 것들 중에서 가장 큰 것 저장. 없으면 -1 저장.
            if(m.size() > 0){
                if(m.top() == maxNum && !duo){
                    tmp = m.top();
                    m.pop();
                    mentors[i] = m.top();
                    m.push(tmp);
                }
                else
                    mentors[i] = m.top();
            }else{
                mentors[i] = -1;
            }
            // 다시 원래대로
            while(temp.size() > 0){
                m.push(temp.back());
                temp.pop_back();
            }
                
        }

        // output
        printf("Case #%d:", tc+1);
        for(i = 0; i < n; i++)
            printf(" %d", mentors[i]);
        printf("\n");
    }
    

    return 0;
}