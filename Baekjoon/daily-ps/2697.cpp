// BOJ - 2697 다음수 구하기, 230102 solved
/** @explaination - 
* 
* 오른쪽 끝부터 탐색하며 오름차순이 끊기는 부분을 체크한 후, (끊기는는 수 - n)
* 끊기는 부분의 오른쪽에 있는 부분수열에서 n보다 큰 최소 요소와 위치를 바꾼 후
* 오른쪽 부분수열에 들어간 n을 적당히 위치를 잡아 주고
* 오른쪽 부분수열을 뒤집어주면 된다.
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int search(string str, int st, int ed, char n);
void swap(char* c1, char* c2);
void insertionSort(string* str, int st, int ed);

int main() {
	fastio;
	int t;
	string A;
	
	cin >> t;
	for (; t > 0; t--) {
		bool isBiggest = true;
		cin >> A;
		
		int len = A.size();
		for (int i = len - 1; i > 0; i--) {
			// 앞 자리가 뒷 자리보다 작을 때 -> 더 커질 수 있음
			if (A[i - 1] < A[i]) {
				isBiggest = false;
				int targetIdx = search(A, i, len - 1, A[i - 1]);	// idx 방식
				swap(&A[i - 1], &A[targetIdx]);	// A[i-1]보다 큰 최소 요소 [i, len)에서 찾아 swap
				insertionSort(&A, targetIdx, len - 1);	// 일단 내림차순 정렬, idx방식
				reverse(A.begin() + i, A.end());
				break;
			}
		}
		if (isBiggest) {
			cout << "BIGGEST\n";
		}
		else {
			cout << A << "\n";
		}
	}
	
	return 0;
}

 
// @info - 범위 내 n보다 큰 최소 요소 인덱스를 반환하는 함수
int search(string str, int st, int ed, char n) {
	int idx = st;
	for (int i = st; i <= ed; i++) {
		if (str[i] <= n) break;
		idx = i;
	}
	return idx;
}

void swap(char* c1, char* c2) {
	char tmp = *c2;
	*c2 = *c1;
	*c1 = tmp;
	return;
}

void insertionSort(string* str, int st, int ed) {
	if (st == ed) return;
	for (int i = st; i < ed; i++) {
		if ((*str)[i] < (*str)[i + 1]) {
			swap(&(*str)[i], &(*str)[i + 1]);
		}
	}
	return;
}