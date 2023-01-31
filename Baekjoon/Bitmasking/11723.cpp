/** 
* 230121 solved, bitmasking
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 20
using namespace std;

int main() {
	fastio;
	bool memory[SIZE] = { 0 };
	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		string str;
		int n;
		cin >> str;
		if (!str.compare("all") || !str.compare("empty")) {
			if (!str.compare("all")) {
				for (int j = 0; j < SIZE; j++) {
					memory[j] = 1;
				}
			}
			else {
				for (int j = 0; j < SIZE; j++) {
					memory[j] = 0;
				}
			}
		}
		else {
			cin >> n;
			if (!str.compare("add")) {
				memory[n - 1] = 1;
			}
			else if (!str.compare("remove")) {
				memory[n - 1] = 0;
			}
			else if (!str.compare("check")) {
				cout << memory[n - 1] << "\n";
			}
			else{
				memory[n - 1] = 1 - memory[n - 1];
			}
		}
	}
	
	return 0;
}