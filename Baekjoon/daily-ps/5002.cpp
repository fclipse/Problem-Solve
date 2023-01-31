#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int diff = 0, maxNum = 0;
char cache[2];
stack<int> s;
map<char, int> m = { {'W', -1}, {'M', 1} };

void popFirst();
void popSecond();
void handlePeople();

int main() {
	fastio;
	int n, len;
	string people;
	cin >> n >> people;
	len = people.length();

	// solving
	bool isFinished = false;
	// stack에 사람들 순서 뒤에서부터 집어넣음
	for (int i = 0; i < len; i++) {
		s.push(people[len - i - 1]);
	}

	// cache에 1, 2번째 사람 정보 집어넣음
	cache[0] = s.top();
	if (s.size() > 1) {
		s.pop();
		cache[1] = s.top();
	}
	else {
		cache[1] = 0;
	}
	
	// stack에 있는 정보 하나씩 빼면서 반복
	while (s.size() > 1 && abs(diff) <= n) {
		if (diff == 0) {
			// 차이 == 0인상태 -> 2번째사람 들여보냄
			popSecond();
			maxNum++;
			diff += m[cache[1]];
		}
		else {
			if (abs(diff + m[cache[0]]) < abs(diff)) {
				// 첫 번째 사람을 들여보냈을때 차이가 줄어들 때
				popFirst();
				maxNum++;
				diff--;
			}
			else if (abs(diff + m[cache[1]]) < abs(diff)) {
				// 두 번째 사람을 들여보냈을때 차이가 줄어들 때
				popSecond();
				maxNum++;
				diff--;
			}
			else {
				// 첫번째든 두번째든 안줄어들때
				if (diff >= n) {
					// 여유 있을때
					isFinished = true;
					diff += m[cache[0]];
					break;
				}
				else {
					popSecond();
					maxNum++;
					diff++;
				}
			}
		}
	}

	if(abs(diff) <= n) {
		// 일단 줄일 수 있으면 줄임
		if (abs(diff + m[cache[0]]) < abs(diff)) {
			// 첫 번째 사람을 들여보냈을때 차이가 줄어들 때
			maxNum++;
			diff--;
			cache[0] = 0;
		}
		else if (abs(diff + m[cache[1]]) < abs(diff)) {
			// 두 번째 사람을 들여보냈을때 차이가 줄어들 때
			maxNum++;
			diff--;
			cache[1] = 0;
		}


		if (cache[0] > 0 && abs(diff + m[cache[0]]) <= n) {
			// 아니면 diff < n이면 추가
			diff += cache[0];
			cache[0] = 0;
			maxNum++;
		}
		if (cache[1] > 0 && abs(diff + m[cache[1]]) <= n) {
			// 아니면 diff < n이면 추가
			diff += cache[1];
			cache[1] = 0;
			maxNum++;
		}
	}
	cout << maxNum;
}

void popFirst() {
	cache[0] = cache[1];
	popSecond();
}
void popSecond() {
	s.pop();
	cache[1] = s.top();
}
void handlePeople(int i, char gender) {
	if (cache[0] == gender) {
		diff += i;
		popSecond();
	}
	else if (cache[1] == gender) {
		diff += i;
		popSecond();
	}
	else {
		diff -= i;
		popFirst();
	}
}