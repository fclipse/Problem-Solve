#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool isUpperCase(char c);

int main() {
	fastio;
    string str;
    cin >> str;

    // solving
    string answer;
    const int diff = 'A' - 'a';
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        if(isUpperCase(c)){
            cout << (char)(c - diff);
        }else{
            cout << (char)(c + diff);
        }
    }

	return 0;
}

bool isUpperCase(char c){
    return 'A' <= c && c <= 'Z';
}