#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int ans = 0;
    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        ans += tmp;
    }
    cout << ans;

	return 0;
}