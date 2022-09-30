// Baekjoon No. 1019 - 책 페이지 220121~220911
// Time Complexity O(logn)
// #Math
/** 
각 자리마다 각 숫자들이 몇 개의 경우의 수를 제공할 수 있는지 케이스를 나누어 각각 세어 답을 구하는 알고리즘
기존의 1~n까지 모든 숫자를 str로 변환해 수를 하나씩 세는 알고리즘은 너무 비효율적임.
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, length;
	int i, j;
	unsigned long long int cnt[10] = { 0 };
	cin >> n;

	// solving
	string number = to_string(n);
	length = number.length();
	// 일의자리~ 맨 상위자리 - 1 까지
	for (i = 0; i < length - 1; i++) {
		// 0은 따로 취급. 0보다 그 자릿수가 작은 경우는 없으므로 그 경우는 제외하고 0일때랑 0이 아닐 때 (클 때)만 고려.
		if(number[length - 1 - i] - '0' != 0)
			cnt[0] += (n / (int)pow(10, i + 1)) * (int)pow(10, i);
		else
			cnt[0] += (n / (int)pow(10, i + 1) - 1) * (int)pow(10, i) + n % (int)pow(10, i) + 1;

		for (j = 1; j < 10; j++) {
			// 그 자리의 숫자 (number[length - 1 - i]) 가 j (현재 가짓수 더하는 수)보다 클 때, 같을 때, 작을 때 세가지로 나누어 분류.
			if (number[length - 1 - i] - '0' > j)
				cnt[j] += (n / (int)pow(10, i + 1) + 1) * (int)pow(10, i);
			else if (number[length - 1 - i] - '0' == j)
				cnt[j] += n / (int)pow(10, i + 1) * (int)pow(10, i) + n % (int)pow(10, i) + 1;
			else
				cnt[j] += (n / (int)pow(10, i + 1)) * (int)pow(10, i);
		}
	}

	i = length - 1;
	// 맨 상위자리
	for (j = 1; j < 10; j++) {
		if (number[0] - '0' > j)
			cnt[j] += (int)pow(10, i);
		if (number[0] - '0' == j) {
			cnt[j] += n % (int)pow(10, i) + 1;
		}
	}
	
	for (i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	return 0;
}