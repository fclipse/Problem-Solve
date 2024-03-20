#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define CONST 20220824

using namespace std;
int main() {
	int n, k;
	int i, tc;
	scanf("%d", &n);
	for (tc = 0; tc < n; tc++) {
		scanf(" %d", &k);
		vector<int> a(k + 1, 0);
		vector<int> b(k + 1, 0);

		a[0] = 1;
		b[0] = 1;
		
		for (i = 1; i <= k; i++) {
			a[i] = (2 * a[i - 1] + b[i - 1]) % CONST;
			b[i] = (a[i - 1] - b[i - 1]) % CONST;
		}
		
		printf("%d %d\n", a[k], b[k]);
	}

	return 0;
}