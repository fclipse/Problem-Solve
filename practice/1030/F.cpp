// Baekjoon No. 11140
// Time Complexity 
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string conditions[3][3] = { {"lol"}, {"lo", "ol", "ll"}, {"l", "o"} };
// *ol, l*l, lo*, ll
int isContain(char, string);
int isContain(string, string);
int main() {
	fastIO
	int t, index, cnt;
	int i, length;
	string str;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		str.clear();
		cin >> str;
		length = str.length();
		if (isContain(conditions[0][0], str))
			cout << 0;
		else if (isContain(conditions[1][0], str) || isContain(conditions[1][1], str) || isContain(conditions[1][2], str))
			cout << 1;
		else if(isContain(conditions[2][0], str) || isContain(conditions[2][1], str) {
			for (i = 0; i < length) {

			}
			if (index = isContain('l', str)) {
				if(index + 2 < length && str[index+2] == str[index])
					cout << 1;	// l*l
			}
			if (index = isContain('o', str)) {

			}

		}else
			cout << 3;
	}
	return 0;
}
// returns 1 if original contains str
int isContain(string str, string original) {
	bool isSame = true;
	int strlen = str.length();
	int cmpNum = original.length() - str.length() + 1;
	for (int i = 0; i < cmpNum; i++) {
		isSame = true;
		for (int j = 0; j < strlen; j++) {
			if (str[i + j] != original[i + j]) {
				isSame = false;
				break;
			}
		}
		if (isSame) return 1;
	}
	return 0;
}
// returns ch's index
int isContain(char ch, string original) {
	int length = original.length();
	for (int i = 0; i < length; i++)
		if (original[i] == ch)
			return i;
	return -1;
}