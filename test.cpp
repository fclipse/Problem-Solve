#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> s;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	
	for (auto i : s) {
		cout << i << " ";
	}
	cout << endl;
	s.erase(2);

	cout << *(s.begin());
}