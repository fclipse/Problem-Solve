#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio;
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int n;
		cin >> n;
		string str = to_string(n);
		vector<int> divisors;
		set<int> combinations;


		for (int i = 1; i <= sqrt(n); i++) {
			if (n % i == 0) {
				divisors.push_back(i);
				if(i != n / i) divisors.push_back(n / i);
			}
		}


	}


	return 0;
}