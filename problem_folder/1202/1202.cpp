#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 300000
using namespace std;

// struct
struct Gem{
    int value, weight;
    bool operator<(const struct Gem& other) const{
        return value < other.value;
    }
};
bool gemComp(Gem g1, Gem g2){
    return g1.weight < g2.weight;
}
// globals
Gem gem[SIZE];
int bag[SIZE] = {0};

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
    long long ans = 0;
    sort(bag, bag + k); // 가방 용량 오름차순 정렬
    sort(gem, gem + n, gemComp); // gem 무게 오름차순 정렬
    
    priority_queue<Gem> q;
    int idx = 0;
    for(int i = 0; i < k; i++){
        while (idx < n && gem[idx].weight <= bag[i]){
            q.emplace(gem[idx]);
            idx++;
        }
        
        if(!q.empty() && q.top().weight <= bag[i]){
            ans += q.top().value;
            q.pop();
        }
    }
    
    // output
    cout << ans;
	return 0;
}