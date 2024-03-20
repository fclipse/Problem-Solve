// Baekjoon No.
// Time Complexity
/*
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int index(string str);

int main() {
	fastIO
	int n, idx;
	int i;
	cin >> n;
	cin.ignore();
	for (i = 0; i < n; i++) {
		int num1, num2;
		string line, n1, n2;
		getline(cin, line);
		// cout << line << "\n";
		
		idx = index(line);
		if (idx < 0) {
			cout << "error\n";
			continue;
		}
		n1 = line.substr(0, idx + 1);
		n2 = line.substr(idx + 1);
		// cout << "n1, n2 : " << n1 << " " << n2 << "\n";
		num1 = stoi(n1);
		num2 = stoi(n2);
		cout << num1 + num2 << "\n";
		
	}
	
	return 0;
}

int index(string str) {
	int i, length = str.size();
	for (i = 0; i < length; i++)
		if (str[i] == ',') return i;
	return -1;
}