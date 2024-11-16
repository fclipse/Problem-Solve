#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 240519 solved
// brute force, combination, sort

// globals
int length;
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

// functions
int validation(vector<char> &target);
void recursive(int idx, int cnt, vector<char> &charSet, vector<char> result);

int main() {
	fastio;
    int charNum;
    cin >> length >> charNum;
    vector<char> charSet(charNum);
    for (int i = 0; i < charNum; i++){
        cin >> charSet[i];
    }
    // solving
    vector<char> result(charNum);
    sort(charSet.begin(), charSet.end());
    // output
    recursive(0, 0, charSet, result);
    
	return 0;
}

// target[] 의 모음의 개수를 반환하는 함수
int validation(vector<char> &target){
    int cnt = 0;
    for (int tIdx = 0; tIdx < length; tIdx++){
        for (int vIdx = 0; vIdx < 5; vIdx++){
            if(target[tIdx] == vowels[vIdx]){
                cnt++;
                break;
            }
        }
    }
    
    return cnt;
}

// 재귀 형태로 모든 조합을 출력하는 함수
// cnt - 이제까지 사용한 글자수, idx - charSet에서 위치한 포인터
void recursive(int idx, int cnt, vector<char> &charSet, vector<char> result){
    if(length == cnt){
        int vowelCnt = validation(result);
        if(vowelCnt >= 1 && length - vowelCnt >= 2){
            // 출력 가능할때
            for (int i = 0; i < length; i++){
                cout << result[i];
            }
            cout << "\n";
        }
        return;
    }
    if(idx >= charSet.size()) return;
    // 현재 글자 사용할 경우
    result[cnt] = charSet[idx];
    recursive(idx + 1, cnt + 1, charSet, result);

    // 현재 글자를 사용하지 않고 다음 글자로 넘어갈 경우
    recursive(idx + 1, cnt, charSet, result);
    return;
}