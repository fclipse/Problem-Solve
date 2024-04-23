#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 300000
using namespace std;

// struct
struct Gem{
    int weight, value;
    bool operator<(const struct Gem& other) const{
        return value > other.value;
    }
};
// globals
Gem gem[SIZE];
int bag[SIZE] = { 0 };

// functions

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> gem[i].weight >> gem[i].value;
    }
    for(int i = 0; i < k; i++){
        cin >> bag[i];
    }

    // solving
    priority_queue<Gem> q;
    for(int i = 0; i < n; i++){
        q.push(gem[i]);
    }
    long long ans = 0;
    sort(bag, bag + k); // 가방 용량 오름차순 정렬
    cout << "bag - ";
    for(int i = 0; i < k; i++){
        cout << bag[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < k; i++){
        bool notExist = false;
        queue<Gem> tmp;
        while(q.top().weight > bag[i]){
            tmp.push(q.top());
            q.pop();
            if(q.empty()){
                notExist = true;
                break;
            }
        }
        // bag에 gem이 들어갈 수 있는 경우
        if(!notExist){
            ans += q.top().value;
            cout << "gem - " << q.top().weight << " " << q.top().value << endl;
            q.pop();
        }
        // tmp에 있던거 모두 다시 q로 이동
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
    }
    // output
    cout << ans;
	return 0;
}
