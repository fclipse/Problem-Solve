#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

map<char, int> romanInt = { 
	{'I', 1}, 
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100}
};

string romans = "IVXLC";

int main() {
	fastIO
	bool special;
	string str;
	getline(cin, str);
	int length = str.size(), res = 0, dist = 0;
	special = 1;
	for (int i = 0; i < length; i++) {
		res += romanInt[str[i]];
		if(i < length - 1) 
			dist = romans.find(str[i + 1]) - romans.find(str[i]);
		if (special && (str[i] == 'I' || str[i] == 'X') && (dist == 1 || dist == 2)) {
			res -= romanInt[str[i]] * 2;
			special = 0;
		}
		else if (!special) {
			special = str[i] != 'C';
		}
	}
	cout << res;
	return 0;
}