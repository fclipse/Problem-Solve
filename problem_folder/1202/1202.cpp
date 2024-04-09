#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// functions
bool comp(int a, int b);
int binSearch(int baseValue, int st, int ed, vector<pair<int, int>> &bag);
int getSmallestBag(int idx, vector<pair<int, int>> &bag, priority_queue<pair<int, int>> &usedBag);

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> gem(n);  // {value, weight} 형태로 저장
    vector<pair<int, int>> bag(k);  // {capability, idx} 형태로 저장
    priority_queue<pair<int, int>> usedBag;  // 이미 사용된 가방들의 idx, 내림차순 순으로 저장됨. / {용량, idx}으로 저장
    
    for(int i = 0; i < n; i++){
        cin >> gem[i].second >> gem[i].first;
    }
    for(int i = 0; i < k; i++){
        cin >> bag[i].first;
        bag[i].second = i;
    }

    // solving
    unsigned long long maxValue = 0;
    sort(gem.begin(), gem.end(), comp); // 보석 가격 내림차순 정렬
    sort(bag.begin(), bag.end()); // 가방 용량 오름차순 정렬

    for(int gemIdx = 0; gemIdx < n; gemIdx++){
        int bagIdx = getSmallestBag(binSearch(gem[gemIdx].second, 0, k, bag), bag, usedBag);
        if(bagIdx < 0) continue;
        // 넣을 수 있는 경우
        usedBag.push(bag[bagIdx]);
        maxValue += gem[gemIdx].first;
    }

    // output
    cout << maxValue;
	return 0;
}

// 내림차순 정렬을 위한 compare 함수
bool comp(int a, int b){
    return a > b;
}

// 이분탐색 - O(N)
// 찾는 가방 중 baseValue보다 크거나 같은 값들 중 가장 작은 값 반환(lower bound)
// bag배열은 오름차순 정렬 되어있음
int binSearch(int baseValue, int st, int ed, vector<pair<int, int>> &bag){
    if(bag[st].first > baseValue) return st;
    if(bag[ed].first < baseValue) return -1;
    int mid = (st + ed) / 2;
    int pivot = bag[mid].first;
    if(pivot == baseValue) return mid;
    else if(pivot < baseValue) return binSearch(baseValue, mid + 1, ed, bag);
    else return binSearch(baseValue, st, mid, bag);
}

// 사용된 가방들 중 기준이 되는 가방보다 크거나 같은 값 중 가장 
int getSmallestBag(int idx, vector<pair<int, int>> &bag, priority_queue<pair<int, int>> &usedBag){
    int result = -1;
    vector<pair<int, int>> tmp;
    pair<int, int> topBag;
    usedBag.
    while(usedBag.top().first > bag[idx].first){
        topBag = usedBag.top();
        tmp.emplace_back(topBag);
        usedBag.pop();

    }
    for(int i = 0; i < tmp.size(); i++){
        usedBag.push(tmp[i]);
    }
    return result;
}