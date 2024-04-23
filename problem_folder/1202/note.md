# 보석 도둑
- 백준 1202
- solving: 240407~

## 생각
1. 가방은 총 k개 주어짐.
- 작은 가방에 넣을 수 있는 보석은 그보다 큰 가방에 넣을 수 있지만, 그 역은 성립 안 함.
    1. 일단 작은 가방부터 보석을 담으면서 최대한 담는 방향으로 진행? -> 그리고 다 담았으면 그 합을 구하기.
- 반례) 마지막에 남은 보석 하나가 남은 보석들 전부의 가격을 다 합친것보다 value가 높으면?
    ㄴ 근데 이 방법으로 남은 보석은 어차피 아무 가방에도 들어갈 수 없음. 각 가방마다 최대로 가능한 보석을 담았는데 거기서 남은 어떤 보석을 선택한 보석 대신 넣어도 손해밖에 안남(4/23)
    2. 그럼 가격이 높은 보석부터 담아야 하나?
- 근데 그럼 또 1.이 가격 합이 더 높아질 수가 있음.
    3. 가격이 높은 보석부터 담되, 각 보석은 들어갈 수 있는 최소 가방에 담으면 될듯? 그러면 각 가방에 들어가는 보석의 value는 해당 가방에 넣을 수 있는 보석들 중 최대가 됨.

-> 알고리즘
    1. 보석을 가격순으로 내림차순 정렬.- O(nlogn)
    2. 가방을 최대허용무게순으로 오름차순 정렬 - O(NlogN)
    3. 각 보석을 '넣을 수 있는'(사용하지 않은) 가장 작은 가방에 넣기
    - 여기가 문제
    시간복잡도 = 보석의 수 N * 넣을 수 있는 가장 작은 가방 찾기 인데,
    가능한 작은 가방을 찾는게 O(N)미만으로 나와야함. 근데 그게 쉽지가 않음..
    가방을 용량순으로 미리 정렬하고 이진탐색하면 O(NlogN), O(logN)이 걸리지만, 가방 사용 여부를 따지게 되면 이진탐색으로 찾고난 뒤, 거기서부터 타고 계속 올라가기게 O(N)이 걸리게 되버림.
    -> 그럼 사용한 가방 배열을 만들고, 거기서 이분탐색을 하면서 들어갈 수 있는 가장 작은 idx를 구한다면?
    ㄴ근데 배열에 push할때 O(N)이 걸려버림..
    -> 사용한 가방으로 priority_queue를 만들고, 거기서 minBagIdx가 나올때까지 pop을 하면서 idx를 구할 때의 시간복잡도는?
    4. 정답 출력
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

2.가방, 보석 모두 무게 기준 오름차순으로 정렬한 뒤
보석의 각 요소 순회하면서
- 첫번째 보석은 이진탐색으로 사용할 수 있는 최소 가방의 인덱스 찾음
- 다음 보석부턴 첫번째 보석의 다음 인덱스부터 순차탐색, 자기 무게보다 큰 가방 나오면 해당 가방에 넣고 넘김
- 이렇게 보든 보석 순회하면서 가격 합 구하기
-> 이렇게 간다면..?
-> 일단 O(k + N)에 해결가능. 
다만 반례가 
    1. n > k이고 마지막 보석의 가치가 제일 높을 때

3. 근데 그냥 naive하게 생각하면 작은 가방부터 각 가방이 가질 수 있는 최대 보석을 가져가면 되는거 아닌가?
    1. 가방 오름차순 정렬
    2. 보석 무게로 오름차순 정렬
    3. 각 가방마다 들어갈 수 있는 보석 최소 idx, 최대 idx 이분탐색으로 구함 (최소idx >= n -> 다음 가방으로 넘어가기, 최대idx <= 0이면 그냥 최고 가치 보석 return)
    4. 해당 범위 전부 순회하면서 최고 가치 보석 찾기 -> 해당 보석 안담았다면 담기
    5. 정답 출력