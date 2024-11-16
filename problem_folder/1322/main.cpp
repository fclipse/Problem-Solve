#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int x, k;
    long long y;
    cin >> x >> k;
    // solving
    bitset<62> xBinary(x);
    bitset<31> kBinary(k);
    bitset<62> answer(0);
    int kLength = kBinary.size();
    int idx = 0, kIdx = 0;
    while(kIdx < kLength && idx < xBinary.size()){
        // answer의 x의 0인 부분과 인덱스가 같은 부분에 k의 각 자리를 집어넣어야 함.
        if(!xBinary[idx]){
            answer[idx] = kBinary[kIdx];
            kIdx++;
        }
        idx++;
    }

    // output
    y = answer.to_ulong();
    cout << y;

	return 0;
}