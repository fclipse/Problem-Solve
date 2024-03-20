#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio;
	string str, res = "";
	stack<char> oper_stack;
	stack<char> alpha_stack;
	map<char, int> oper_priority = { {'(', 2}, {')', 2}, {'*', 1}, {'/', 1}, {'+', 0}, {'-', 0}};

	cin >> str;
	for(int i = 0; i < str.size(); i++){
		char c = str[i];
		if ('A' <= c && c <= 'Z') {	// 알파벳일 때
			alpha_stack.push(c);
		}
		else {						// 연산자일 때
			char top = oper_stack.top();
			if (oper_priority[top] > oper_priority[c]) {
				
				res += 
			}
		}

	}

	return 0;
}