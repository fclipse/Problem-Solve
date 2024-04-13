#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int t;
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++){
        string str;
        getline(cin, str);
        int length = str.size();
        cout << str[0] << str[length - 1] << "\n";
    }

	return 0;
}