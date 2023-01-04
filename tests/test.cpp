#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF (int)(1<<31) - 1
using namespace std;

void swap(char* c1, char* c2);
void f(string* str);

int main() {
	fastIO;

	string A = "hello";
	f(&A);
	
	
	cout << A;

	return 0;
}

void swap(char* c1, char* c2) {
	char tmp = *c2;
	*c2 = *c1;
	*c1 = tmp;
	return;
}

void f(string* str) {
	swap(&(*str)[0], &(*str)[4]);
}